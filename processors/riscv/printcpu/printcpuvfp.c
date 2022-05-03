#include <config.h>

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define COG 1
#define FOR_COG_PLUGIN 1

#include <sim-main.h>

static char buf[10];

char *
lower(char *s)
{
	int i;
	for (i = 0; i < strlen(s); i++)
		buf[i] = tolower(s[i]);
	buf[i] = 0;
	return buf;
}

# define CLASS "!RiscVAlien"

int
main()
{
//#define offsetof(type,field) (long)(&(((type *)0)->field))
#define stoffsetof(type,field) (offsetof(type,field)+1)
#define print(n,r) \
printf(CLASS " methodsFor: 'accessing' stamp: 'LM/WoC %d/%d/%d %d:%02d'!\r"\
	"%s\r\t^self unsignedLongLongAt: %ld! !\r", m,d,y,h,i, lower(#r), \
	stoffsetof(struct _sim_cpu,fpregs[n]));\
printf(CLASS " methodsFor: 'accessing' stamp: 'LM/WoC %d/%d/%d %d:%02d'!\r"\
	"%s: anUnsignedInteger\r\t^self unsignedLongLongAt: %ld put: anUnsignedInteger! !\r", m,d,y,h,i, lower(#r), \
	stoffsetof(struct _sim_cpu,fpregs[n]))

	time_t nowsecs = time(0);
	struct tm now = *localtime(&nowsecs);
	int m = now.tm_mon + 1; /* strange but true */
	int d = now.tm_mday;
	int y = now.tm_year + 1900;
	int h = now.tm_hour;
	int i = now.tm_min;

	printf("\"Hello world!!\"!\r");
	printf(CLASS " class methodsFor: 'instance creation' stamp: 'LM/WoC %d/%d/%d %d:%02d'!\r"
	"dataSize\r\t^%ld! !\r", m,d,y,h,i, sizeof(struct _sim_cpu));

	print(0,f0);
	print(1,f1);
	print(2,f2);
	print(3,f3);
	print(4,f4);
	print(5,f5);
	print(6,f6);
	print(7,f7);
	print(8,f8);
	print(9,f9);
	print(10,f10);
	print(11,f11);
	print(12,f12);
	print(13,f13);
	print(14,f14);
	print(15,f15);
	print(16,f16);
	print(17,f17);
	print(18,f18);
	print(19,f19);
	print(20,f20);
	print(21,f21);
	print(22,f22);
	print(23,f23);
	print(24,f24);
	print(25,f25);
	print(26,f26);
	print(27,f27);
	print(28,f28);
	print(29,f29);
	print(30,f30);
	print(31,f31);

	return 0;
}
