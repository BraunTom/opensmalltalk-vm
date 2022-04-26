XCPPFLAGS=	-fPIC \
			-I$(topdir)/processors/riscv_em/src/core \
			-I$(topdir)/processors/riscv_em/src/core/csr \
			-I$(topdir)/processors/riscv_em/src/core/pmp \
			-I$(topdir)/processors/riscv_em/src/core/trap \
			-I$(topdir)/processors/riscv_em/src/core/mmu \
			-I$(topdir)/processors/riscv_em/src/peripherals/clint \
			-I$(topdir)/processors/riscv_em/src/peripherals/plic \
			-I$(topdir)/processors/riscv_em/src/peripherals/uart \
			-I$(topdir)/processors/riscv_em/src/helpers \
			-I$(topdir)/processors/riscv_em/src/soc/

XLDFLAGS=	-L$(topdir)/processors/riscv_em/build \
			-lriscv_em
