#define LINEBREAK "\n---------------------\n"

//#define SIMPLE_REPORT

void setReporting(int);
void beginTest(char *);
void endTest(char *);
int assertTrue(int, char *);
int assertFalse(int, char *);