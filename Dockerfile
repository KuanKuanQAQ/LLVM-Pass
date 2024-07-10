# =============================================================================
# An Ubuntu docker file for llvm & gcc that compile Linux kernel via apt. 
# It uses the precompiled LLVM packages from Ubuntu.
#
# USAGE:
# ```bash
# docker build -t=x:v0 .
# docker run -it --privileged=true x:v0 zsh
# ```
# =============================================================================

FROM ubuntu:22.04 AS base

SHELL ["/bin/bash", "-c"]
COPY id_rsa /root/.ssh/

# Change to tsinghua mirrors
RUN sed -i 's/http:\/\/ports.ubuntu.com/http:\/\/mirrors.tuna.tsinghua.edu.cn/g' /etc/apt/sources.list
RUN apt update && apt upgrade -y && rm -rf /var/lib/apt/lists/*

# Install language
RUN apt update && apt-get install -y locales \
    && locale-gen en_US.UTF-8 \
    && update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 \
    && rm -rf /var/lib/apt/lists/*
ENV LANG en_US.UTF-8

# Install timezone
RUN ln -fs /usr/share/zoneinfo/Asia/Shanghai /etc/localtime \
    && apt update && apt install -y tzdata \
    && dpkg-reconfigure --frontend noninteractive tzdata \
    && rm -rf /var/lib/apt/lists/*

# Install common programs
RUN apt update && apt install -y --no-install-recommends \
    curl gnupg2 lsb-release sudo software-properties-common \
    git cmake wget gdb vim zsh ssh qemu-system iputils-ping \
    && rm -rf /var/lib/apt/lists/*

RUN apt update && apt install -y gcc-12 g++-12 build-essential \
    libssl-dev libncurses-dev ninja-build \
    python3-minimal python3-pip python3-setuptools \
    software-properties-common flex bison bc cpio \
    && rm -rf /var/lib/apt/lists/*

# Get SSH private key
RUN eval `ssh-agent -s` && ssh-add /root/.ssh/id_rsa

# Install llvm-17 from precompiled LLVM packages
RUN wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -
RUN apt-add-repository "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-17 main"
RUN apt update && apt install -y \
    llvm-17 llvm-17-dev llvm-17-tools clang-17 \
    && rm -rf /var/lib/apt/lists/*

# Modify config
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 100 --slave /usr/bin/g++ g++ /usr/bin/g++-12
# RUN git clone https://github.com/KuanKuanQAQ/My-Vim-Config.git /root/.vim && cp /root/.vim/.vimrc.example /root/.vimrc
RUN echo "y"|sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"

WORKDIR /root
CMD /bin/bash