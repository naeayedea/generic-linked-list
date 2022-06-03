#include <stdio.h>
#include "test-framework.h"

int reporting = 1;

void setReporting(int value) {
    reporting = value;
}

void beginTest(char * testName) {
#ifdef SIMPLE_REPORT
    setReporting(0);
#endif
    if (reporting) {
        printf(LINEBREAK);
        printf("Beginning %s tests:\n\n", testName);
    }
}

void endTest(char * testName) {
    if (reporting) {
        printf("\nEnd of %s tests\n", testName);
        printf(LINEBREAK);
    }
#ifdef SIMPLE_REPORT
    setReporting(1);
#endif
}

int assertTrue(int expression, char * testName) {
    if (reporting) {
        return (expression ? (printf("%s passed\n", testName) && 0) : printf("%s failed\n", testName)) == 0;
    } else {
        return expression;
    }
}

int assertFalse(int expression, char *testName) {
    if (reporting) {
        return (expression ? printf("%s failed\n", testName) : (printf("%s passed\n", testName) && 0)) == 0;
    } else {
        return !expression;
    }
}