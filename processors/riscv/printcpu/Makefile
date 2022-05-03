RISCVSRC=../../../processors/riscv/gdb-12.1/
RISCVBUILD=../../../building/linux64x64/riscv
INCLUDES := -I$(RISCVBUILD)/sim/common \
		-I$(RISCVBUILD)/bfd \
		-I$(RISCVBUILD)/gdb \
		-I$(RISCVBUILD)/ \
		-I$(RISCVSRC)/include \
		-I$(RISCVSRC)/sim/riscv \
		-I$(RISCVSRC)/sim/common \
		-I$(RISCVSRC)/bfd
LIBS:=	-L$(RISCVBUILD)/bfd \
	-L$(RISCVBUILD)/opcodes \
	-L$(RISCVBUILD)/sim/riscv \
	-L$(RISCVBUILD)/libiberty \
	-L$(RISCVBUILD)/gnulib/import \
	-lsim -lopcodes -lbfd -liberty -lz -lgnu -lm

GDBRISCVPRINTCPU=.
CLASS=RiscVAlien

CFLAGS=-m64 -DCOG=1 -DMODET -DWITH_PROFILE=-1 -DWITH_TARGET_BYTE_ORDER=BFD_ENDIAN_LITTLE $(INCLUDES) $(LIBS)

all: ${CLASS}-regs.st ${CLASS}-ctrl.st ${CLASS}-vfp.st

${CLASS}-regs.st: printcpu
	./printcpu > $@

# ${CLASS}-ctrl.st: printcpuctrl
	# ./printcpuctrl > $@

${CLASS}-vfp.st: printcpuvfp
	./printcpuvfp > $@

.PHONY: clean
clean:
	rm -f ${CLASS}-regs.st ${CLASS}-vfp.st
	rm -f printcpu printcpuctrl printcpuvfp

printcpu: $(GDBRISCVPRINTCPU)/printcpu.c
	$(CC) -o $@ $< $(CFLAGS)

# printcpuctrl: $(GDBRISCVPRINTCPU)/printcpuctrl.c
	# $(CC) -o $@ $< $(CFLAGS)

printcpuvfp: $(GDBRISCVPRINTCPU)/printcpuvfp.c
	$(CC) -o $@ $< $(CFLAGS)
