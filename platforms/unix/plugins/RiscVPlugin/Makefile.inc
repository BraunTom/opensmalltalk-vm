GDBBUILDFOLDER	= ../../../riscv/
GDBSOURCEFOLDER	= ../../../../../processors/riscv/gdb-12.1

XCFLAGS += -DWITH_TARGET_WORD_BITSIZE=64

XINCLUDES	+= -I$(GDBSOURCEFOLDER)/include
XINCLUDES	+= -I$(GDBSOURCEFOLDER)/opcodes
XINCLUDES	+= -I$(GDBSOURCEFOLDER)/sim/riscv
XINCLUDES	+= -I$(GDBSOURCEFOLDER)/sim/common
XINCLUDES	+= -I$(GDBSOURCEFOLDER)/bfd

XINCLUDES	+= -I$(GDBBUILDFOLDER)/
XINCLUDES	+= -I$(GDBBUILDFOLDER)/sim
XINCLUDES	+= -I$(GDBBUILDFOLDER)/sim/common
XINCLUDES	+= -I$(GDBBUILDFOLDER)/bfd

XLDFLAGS=	-L$(GDBBUILDFOLDER)/bfd \
					-L$(GDBBUILDFOLDER)/opcodes \
					-L$(GDBBUILDFOLDER)/sim/riscv \
					-L$(GDBBUILDFOLDER)/libiberty \
					-L$(GDBBUILDFOLDER)/gnulib/import \
					-lsim -lopcodes -lbfd -liberty -lz -lgnu \
					-Wl
