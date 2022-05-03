#include <config.h>

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define COG 1
#define FOR_COG_PLUGIN 1
# define CLASS "!RiscVAlien"

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

#define stoffsetof(type,field) (offsetof(type,field)+1)
#define print(n,r) \
printf(CLASS " methodsFor: 'accessing' stamp: 'LM/WoC %d/%d/%d %d:%02d'!\r"\
	"%s\r\t^self unsignedLongLongAt: %ld! !\r", m,d,y,h,i, lower(#r), \
	stoffsetof(struct _sim_cpu,regs[n]));\
printf(CLASS " methodsFor: 'accessing' stamp: 'LM/WoC %d/%d/%d %d:%02d'!\r"\
	"%s: anUnsignedInteger\r\t^self unsignedLongLongAt: %ld put: anUnsignedInteger! !\r", m,d,y,h,i, lower(#r), \
	stoffsetof(struct _sim_cpu,regs[n]))

#define printpc(r) \
printf(CLASS " methodsFor: 'accessing' stamp: 'LM/WoC %d/%d/%d %d:%02d'!\r"\
	"%s\r\t^self unsignedLongLongAt: %ld! !\r", m,d,y,h,i, lower(#r), \
	stoffsetof(struct _sim_cpu,pc));\
printf(CLASS " methodsFor: 'accessing' stamp: 'LM/WoC %d/%d/%d %d:%02d'!\r"\
	"%s: anUnsignedInteger\r\t^self unsignedLongLongAt: %ld put: anUnsignedInteger! !\r", m,d,y,h,i, lower(#r), \
	stoffsetof(struct _sim_cpu,pc))

int
main()
{
//#define offsetof(type,field) (long)(&(((type *)0)->field))
	time_t nowsecs = time(0);
	struct tm now = *localtime(&nowsecs);
	int m = now.tm_mon + 1; /* strange but true */
	int d = now.tm_mday;
	int y = now.tm_year + 1900;
	int h = now.tm_hour;
	int i = now.tm_min;

	printf("\"Hello world!!\"!\r");
	printf(CLASS " class methodsFor: 'instance creation' stamp: 'eem %d/%d/%d %d:%02d'!\r"
	"dataSize\r\t^%ld! !\r", m,d,y,h,i, sizeof(struct sim_state));

	print(0,x0);
	print(1,x1);
	print(2,x2);
	print(3,x3);
	print(4,x4);
	print(5,x5);
	print(6,x6);
	print(7,x7);
	print(8,x8);
	print(9,x9);
	print(10,x10);
	print(11,x11);
	print(12,x12);
	print(13,x13);
	print(14,x14);
	print(15,x15);
	print(16,x16);
	print(17,x17);
	print(18,x18);
	print(19,x19);
	print(20,x20);
	print(21,x21);
	print(22,x22);
	print(23,x23);
	print(24,x24);
	print(25,x25);
	print(26,x26);
	print(27,x27);
	print(28,x28);
	print(29,x29);
	print(30,x30);
	print(31,x31);
	printpc(pc);

	return 0;
}
