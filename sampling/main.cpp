// (c) 2019 by dbj.org -- CC BY-SA 4.0 -- https://creativecommons.org/licenses/by-sa/4.0/ 

// #define TESTING_DBJ_RETVALS
#include <vld.h>
#include "common.h"

/// #include "jzon_udl.h"
#include "tests.h"
#include "test-boxing.h"
#include "json-checker-fail.h"
#include "conformance-string.h"
#include "conformance-double.h"


#pragma warning( push )
#pragma warning( disable: 4100 )
// https://msdn.microsoft.com/en-us/library/26kb9fy0.aspx 

// just execute all the registered tests
// in no particular order
static void dbj_program_start(
	const	int	   argc,
	const	char * argv[],
	const	char * envp[]
)
{
	DBJ_PRINT(DBJ_FG_CYAN "dbj++nanolib version: %s" , dbj::nanolib::VERSION  );
	// call the test units registered, in random order
	// in this scenario easiest is to place the break point 
	// in the test unit of interest
	// if argumet is true, only tu's listing will be shown
	dbj::tu::catalog.execute( /*true*/ );
	dbj::nanolib::system_call("pause");
}

#pragma warning( pop ) // 4100

int main(int argc, const char* argv[], const char* envp[])
{

#ifdef DBJ_REDIRECT_STD_IN
	if (freopen("input.txt", "r", stdin) == NULL) {
		// Handle error, errno is set to indicate error
	}
#endif

#ifdef DBJ_REDIRECT_STD_OUT
	std::string logfile_name(argv[0]);
	logfile_name.append(".log");

#ifndef NDEBUG
	DBJ_PRINT("local log file: %s", logfile_name.c_str());
#endif
	// https://stackoverflow.com/a/46869216/10870835
	if (freopen(logfile_name.c_str(), "w", stdout) == NULL) {
		// Handle error, errno is set to indicate error
		perror( "\n\n" __FILE__ "\n\nCould not redirect stdout? " );
		exit( EXIT_FAILURE );
	}
#endif // DBJ_REDIRECT_STD_OUT

	auto main_worker = [&]() {
			dbj_program_start(argc, argv, envp);
	};

	(void)std::async(std::launch::async, [&] {
		main_worker();
		});

	exit(EXIT_SUCCESS);
}



