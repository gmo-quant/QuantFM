#include"testing.h"

/*whether debug messages are enabled*/
static bool debugEnabled = false;

bool isDebugEnalbed(){
	return debugEnabled;
}

void setDebugEnabled(bool enable){
	debugEnabled = enable;
}