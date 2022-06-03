#include <stdio.h>
#include "test-framework.h"

void beginTest(char * testName) {
    printf(LINEBREAK);
    printf("Beginning %s tests:\n\n", testName);
}

void endTest(char * testName) {
    printf("\nEnd of %s tests\n", testName);
    printf(LINEBREAK);
}

int assertTrue(int expression, char * testName) {
    return (expression ? (printf("%s passed\n", testName) && 0) : printf("%s failed\n", testName)) == 0;
}

int assertFalse(int expression, char *testName) {
    return (expression ? printf("%s failed\n", testName) : (printf("%s passed\n", testName) && 0)) == 0;
}