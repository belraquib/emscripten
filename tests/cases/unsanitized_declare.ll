; ModuleID = 'tests/hello_world.bc'
target datalayout = "e-p:32:32-i64:64-v128:32:128-n32-S128"
target triple = "asmjs-unknown-emscripten"

@.str = private unnamed_addr constant [15 x i8] c"hello, world!\0A\00", align 1

declare i32 @printf(i8*, ...)

; we'll emit a stub to error at runtime, and must sanitize the name for JS
declare void @"<silly>"()

define i32 @main() {
entry:
  %retval = alloca i32, align 4
  store i32 0, i32* %retval
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @.str, i32 0, i32 0))
  %zero = trunc i32 0 to i1
  br i1 %zero, label %no, label %yes

no:
  call void @"<silly>"()
  br label %yes

yes:
  ret i32 0
}

