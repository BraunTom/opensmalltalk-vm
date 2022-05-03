GDB=../../../processors/gdb-12.1
PREREQUISITES:= ../riscv/sim/riscv/libsim.a

INCDIRS:=$(GDB)/include $(GDB)/opcodes $(GDB)/sim/riscv $(GDB)/sim/common $(GDB)/bfd ../riscv/bfd ../riscv/sim ../riscv ../riscv/sim/common
INCFIRST:=$(GDB)/include $(GDB)/opcodes $(GDB)/sim/riscv $(GDB)/sim/common $(GDB)/bfd ../riscv/bfd ../riscv/sim ../riscv ../riscv/sim/common
XCFLAGS:=-DWITH_PROFILE=-1

# assert uses warning, which is in the VM, so -undefined dynamic_lookup needed
ifeq ($(CONFIGURATION),assert)
    EXTRA_FOR_ASSERT:=-undefined dynamic_lookup
else ifeq ($(CONFIGURATION),debug)
    EXTRA_FOR_ASSERT:=-undefined dynamic_lookup
    BUILD:=builddbg 
else # default CONFIGURATION=product
    EXTRA_FOR_ASSERT:=
endif 
EXTRALIBS:= -L../riscv/bfd -L../riscv/libiberty \
			-L../riscv/opcodes -L../riscv/sim/riscv \
			-lbfd -liberty -lopcodes -lopcodes -lsim -lz \
			$(EXTRA_FOR_ASSERT)

include ../common/Makefile.plugin

INCDIRS:= $(INCFIRST) $(MAKERVMDIR) $(CROSSVMDIR) $(MAKERDIR) $(OSXPLGDIR) $(OSXVMDIR) $(CROSSDIR)
INCLUDES:= $(addprefix -I,. $(INCDIRS))
