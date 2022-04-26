# copied from bochs

# BOX:=../bochsx64
# PREREQUISITES:=$(BOX)/cpu/libcpu.a $(BOX)/disasm/libdisasm.a $(BOX)/fpu/libfpu.a

# LINK_WITH_CXX:=1
# INCDIRS:=$(BOX) \
         ../../../processors/IA32/bochs \
		 ../../../processors/IA32/bochs/instrument/stubs
# EXTRALIBS:=	-L$(BOX)/cpu -L$(BOX)/fpu -L$(BOX)/disasm -lcpu -lfpu -ldisasm
# CFLAGS:=-DUSE_BOCHS_CONFIG_H=1

RISCV:=../../../processors/riscv_em/build
PREREQUISITES:=$(RISCV)/libriscv_em.a

INCDIRS:=../../../processors/riscv_em/src/core \
			../../../processors/riscv_em/src/core/csr \
			../../../processors/riscv_em/src/core/mmu \
			../../../processors/riscv_em/src/core/pmp \
			../../../processors/riscv_em/src/core/trap \
			../../../processors/riscv_em/src/helpers \
			../../../processors/riscv_em/src/peropherals \
			../../../processors/riscv_em/src/soc
			

EXTRALIBS:=	-L$(RISCV) -lriscv_em


include ../common/Makefile.plugin
