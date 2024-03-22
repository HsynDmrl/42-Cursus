#include <stdio.h>

// Struct2'nin tanımı
typedef struct struct2 {
    int var2;
    struct struct1 *ptr1; // struct1 işaretçisini kullanacağız, bu nedenle struct1 önceden tanımlanmalıdır
} struct2;

// Struct1'in tanımı
typedef struct struct1 {
    int var1;
    struct struct2 *ptr2; // struct2 işaretçisini kullanacağız, bu nedenle struct2 önceden tanımlanmalıdır
} struct1;

int main() {
    struct1 s1;
    struct2 s2;

    s1.var1 = 10;
    s2.var2 = 20;

    // Pointer'ları dolduralım
    s1.ptr2 = &s2;
    s2.ptr1 = &s1;

    // Erişim örneği
    printf("var1: %d\n", s1.var1);
    printf("var2 via ptr2: %d\n", s1.ptr2->var2);

    printf("var2: %d\n", s2.var2);
    printf("var1 via ptr1: %d\n", s2.ptr1->var1);

    return 0;
}
