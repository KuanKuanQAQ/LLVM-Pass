; ModuleID = '../inputs/input_for_hello.c'
source_filename = "../inputs/input_for_hello.c"
target datalayout = "e-m:e-i8:8:32-i16:16:32-i64:64-i128:128-n32:64-S128"
target triple = "aarch64-unknown-linux-gnu"

%struct.ab = type { i32 }
%struct.elevator_type = type { i32, %struct.elevator_mq_ops }
%struct.elevator_mq_ops = type { ptr, ptr }

@a = dso_local global i32 0, align 4
@x = dso_local global %struct.ab zeroinitializer, align 4
@iosched_bfq_mq = internal global %struct.elevator_type { i32 1, %struct.elevator_mq_ops { ptr @bar, ptr @fez } }, align 8

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @foo(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = mul nsw i32 %3, 2
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @bar(i32 noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  store i32 %2, ptr %6, align 4
  %7 = load i32, ptr %4, align 4
  %8 = load i32, ptr %4, align 4
  %9 = load i32, ptr %5, align 4
  %10 = add nsw i32 %8, %9
  %11 = mul nsw i32 %10, 2
  %12 = add nsw i32 %7, %11
  %13 = load i32, ptr %6, align 4
  %14 = add nsw i32 %12, %13
  ret i32 %14
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @fez(i32 noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  store i32 %2, ptr %6, align 4
  %7 = load i32, ptr %4, align 4
  %8 = load i32, ptr %4, align 4
  %9 = load i32, ptr %5, align 4
  %10 = add nsw i32 %8, %9
  %11 = load i32, ptr %6, align 4
  %12 = add nsw i32 %10, %11
  %13 = mul nsw i32 %12, 2
  %14 = add nsw i32 %7, %13
  %15 = load i32, ptr %6, align 4
  %16 = mul nsw i32 %15, 3
  %17 = add nsw i32 %14, %16
  ret i32 %17
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main(i32 noundef %0, ptr noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca ptr, align 8
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  %9 = alloca i32, align 4
  store i32 0, ptr %3, align 4
  store i32 %0, ptr %4, align 4
  store ptr %1, ptr %5, align 8
  store i32 123, ptr %6, align 4
  %10 = load i32, ptr %6, align 4
  %11 = call i32 @foo(i32 noundef %10)
  store i32 %11, ptr %7, align 4
  %12 = call i32 @rand() #2
  %13 = srem i32 %12, 2
  store i32 %13, ptr %9, align 4
  %14 = load i32, ptr %6, align 4
  %15 = load i32, ptr %7, align 4
  %16 = call i32 @bar(i32 noundef %14, i32 noundef %15, i32 noundef 15)
  %17 = load i32, ptr %7, align 4
  %18 = add nsw i32 %17, %16
  store i32 %18, ptr %7, align 4
  %19 = load i32, ptr %6, align 4
  %20 = load i32, ptr %7, align 4
  %21 = call i32 @fez(i32 noundef %19, i32 noundef %20, i32 noundef 123)
  %22 = load i32, ptr %7, align 4
  %23 = add nsw i32 %22, %21
  store i32 %23, ptr %7, align 4
  %24 = load i32, ptr @x, align 4
  %25 = load i32, ptr %7, align 4
  %26 = add nsw i32 %25, %24
  store i32 %26, ptr %7, align 4
  %27 = load i32, ptr @iosched_bfq_mq, align 8
  %28 = load i32, ptr %7, align 4
  %29 = add nsw i32 %28, %27
  store i32 %29, ptr %7, align 4
  %30 = load i32, ptr %9, align 4
  %31 = icmp ne i32 %30, 0
  br i1 %31, label %32, label %33

32:                                               ; preds = %2
  store ptr @bar, ptr %8, align 8
  br label %34

33:                                               ; preds = %2
  store ptr @fez, ptr %8, align 8
  br label %34

34:                                               ; preds = %33, %32
  %35 = load ptr, ptr %8, align 8
  %36 = call i32 %35(i32 noundef 1, i32 noundef 2, i32 noundef 3)
  %37 = load i32, ptr %7, align 4
  ret i32 %37
}

; Function Attrs: nounwind
declare i32 @rand() #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="generic" "target-features"="+fp-armv8,+neon,+outline-atomics,+v8a,-fmv" }
attributes #1 = { nounwind "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="generic" "target-features"="+fp-armv8,+neon,+outline-atomics,+v8a,-fmv" }
attributes #2 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 1}
!5 = !{!"Ubuntu clang version 17.0.6 (++20231209124227+6009708b4367-1~exp1~20231209124336.77)"}
