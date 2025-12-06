//file pitsTT6libv1.4.h									1/15/98

#ifndef __PITSTT6__
#define __PITSTT6__

#ifdef __cplusplus
extern "C" {
#endif

//function prototypes for pitsTT6lib functions

//version 1.4 of pitsTT6lib added ability to define a sampling schedule in
//a separate file (named fileName.samp, where "fileName" is the same as 
//used in the call to startTrace).  If such a file is present, it is read
//and its contents used to define a sampling schedule.  The file is ASCII,
//with each line containing two white space separated longs:
//
//	onCount offCount
//
//which means record 'onCount' # of instructions after skipping 'offCount' #
//once the sampling schedule is finished, tracing stops, even if the
//final 'stopTrace()' has not been encountered
//
//only the first 1024 lines of the the sample file are read 

short 		startTrace(char *);				//input = trace file name
short		stopTrace(void);				//return = # instructions traced

//alternate forms of the start and stop calls are provided which take void *
//input args: the idea is to pass addresses of local variables so that the 
//optimizer will not move the calls (and thus change the code traced)
short		startTrace_alt(char *, void *);
short		stopTrace_alt(void *);

//pauseTrace() and resumeTrace() calls: note that these also take void * args.
//keeping these calls in proper sequence is the callers
//responsibility - making incorrectly nested calls produce bad results.
//also note that using these calls introduces 'discontinuities' in the 
//produced tt6 trace
void		pauseTrace(void *);
void		resumeTrace(void *);

#ifdef __cplusplus
}
#endif

#endif /* __PITSTT6__ */
