// RUN: %clang_cc1 -triple arm-unknown-linux-gnueabi -emit-llvm -o - %s | FileCheck %s

// CHECK: declare i32 @printf(i8*, ...)
void f0() {
  printf("a\n");
}

// CHECK: call void @exit
// CHECK: unreachable
void f1() {
  exit(1);
}

// CHECK: call i8* @strstr{{.*}} nounwind
char* f2(char* a, char* b) {
  return __builtin_strstr(a, b);
}
