# To build the RiscVPlugin one must build libsim.a from gdb
if test -f ../../riscv/sim/riscv/libsim.a; then
	echo "libsim.a has been built; building GdbARMPlugin"
else
	echo "../../riscv/sim/riscv/libsim.a has not been built; not building GdbARMPlugin"
  AC_PLUGIN_DISABLE
fi
