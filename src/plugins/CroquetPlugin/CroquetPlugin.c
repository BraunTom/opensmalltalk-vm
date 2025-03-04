/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.3166 uuid: bda1c176-bedf-4490-bb95-90d3851c1526
   from
	CroquetPlugin VMMaker.oscog-eem.3166 uuid: bda1c176-bedf-4490-bb95-90d3851c1526
 */
static char __buildInfo[] = "CroquetPlugin VMMaker.oscog-eem.3166 uuid: bda1c176-bedf-4490-bb95-90d3851c1526 " __DATE__ ;


#include "config.h"
#include <math.h>
#include "sqMathShim.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#include "CroquetPlugin.h"
#include "sqMemoryAccess.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
# define INT_EXT "(i)"
#else
# define INT_EXT "(e)"
#endif


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveAdj3(void);
EXPORT(sqInt) primitiveARC4Transform(void);
EXPORT(sqInt) primitiveDet3(void);
EXPORT(sqInt) primitiveGatherEntropy(void);
EXPORT(sqInt) primitiveInplaceHouseHolderInvert(void);
EXPORT(sqInt) primitiveInverseByAdjoint(void);
EXPORT(sqInt) primitiveMD5Transform(void);
EXPORT(sqInt) primitiveOptimizeVertexIndicesForCacheLocality(void);
EXPORT(sqInt) primitiveOrthoNormInverseMatrix(void);
EXPORT(sqInt) primitiveTransformDirection(void);
EXPORT(sqInt) primitiveTransformMatrixWithInto(void);
EXPORT(sqInt) primitiveTransformVector3(void);
EXPORT(sqInt) primitiveTransposeMatrix(void);
EXPORT(sqInt) primitiveTriBoxIntersects(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
static sqInt transformMatrixwithinto(float *src, float *arg, float *dst);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classPoint)(void);
static sqInt (*cloneObject)(sqInt oop);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*isWords)(sqInt oop);
static sqInt (*methodArgumentCount)(void);
static sqInt (*methodReturnBool)(sqInt boolean);
static sqInt (*methodReturnFloat)(double aFloat);
static sqInt (*methodReturnReceiver)(void);
static sqInt (*methodReturnValue)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popRemappableOop)(void);
static sqInt (*positive32BitIntegerFor)(unsigned int integerValue);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*push)(sqInt object);
static sqInt (*pushRemappableOop)(sqInt oop);
static sqInt (*slotSizeOf)(sqInt oop);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackObjectValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*storePointerofObjectwithValue)(sqInt index, sqInt oop, sqInt valuePointer);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classPoint(void);
extern sqInt cloneObject(sqInt oop);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt isBytes(sqInt oop);
extern sqInt isWords(sqInt oop);
extern sqInt methodArgumentCount(void);
extern sqInt methodReturnBool(sqInt boolean);
extern sqInt methodReturnFloat(double aFloat);
extern sqInt methodReturnReceiver(void);
extern sqInt methodReturnValue(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt popRemappableOop(void);
extern sqInt positive32BitIntegerFor(unsigned int integerValue);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt push(sqInt object);
extern sqInt pushRemappableOop(sqInt oop);
extern sqInt slotSizeOf(sqInt oop);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackObjectValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern sqInt storePointerofObjectwithValue(sqInt index, sqInt oop, sqInt valuePointer);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName = "CroquetPlugin VMMaker.oscog-eem.3166 " INT_EXT;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}


/*	Computes the adjoint of the Matrix4x4 receiver,
	placing the results the the Matrix4x4 argument,
	 */

	/* CroquetPlugin>>#primitiveAdj3 */
EXPORT(sqInt)
primitiveAdj3(void)
{
    const int c11 = 0;
    const int c12 = 1;
    const int c13 = 2;
    const int c21 = 4;
    const int c22 = 5;
    const int c23 = 6;
    const int c31 = 8;
    const int c32 = 9;
    const int c33 = 10;
    float *dst;
    sqInt dstOop;
    double m11;
    double m12;
    double m13;
    double m21;
    double m22;
    double m23;
    double m31;
    double m32;
    double m33;
    float *src;
    sqInt srcOop;


	/* <var: #c14 declareC: 'const int c14 = 3'> */
	/* <var: #c24 declareC: 'const int c24 = 7'> */
	/* <var: #c34 declareC: 'const int c34 = 11'> */
	/* then we need the following no-op to make Smalltalk shut up about vars not being initted. */
	srcOop = stackObjectValue(1);
	dstOop = stackObjectValue(0);
	if (failed()) {
		return null;
	}
	src = ((float *) (firstIndexableField(srcOop)));

	/* read in the source matrix 3x3, which contains the encoded rotation and scale factors */
	dst = ((float *) (firstIndexableField(dstOop)));
	m11 = src[c11];
	m12 = src[c12];
	m13 = src[c13];
	m21 = src[c21];
	m22 = src[c22];
	m23 = src[c23];
	m31 = src[c31];
	m32 = src[c32];

	/* do the actual work */
	/* compute our cofactors and transpose.  adj = transpose of cofactors */
	m33 = src[c33];
	dst[c11] = ((m22 * m33) - (m23 * m32));
	dst[c21] = (0.0 - ((m21 * m33) - (m23 * m31)));
	dst[c31] = ((m21 * m32) - (m22 * m31));
	dst[c12] = (0.0 - ((m12 * m33) - (m13 * m32)));
	dst[c22] = ((m11 * m33) - (m13 * m31));
	dst[c32] = (0.0 - ((m11 * m32) - (m12 * m31)));
	dst[c13] = ((m12 * m23) - (m13 * m22));
	dst[c23] = (0.0 - ((m11 * m23) - (m13 * m21)));
	dst[c33] = ((m11 * m22) - (m12 * m21));
	return methodReturnValue(dstOop);
}


/*	Perform an ARC4 transform of input.
	Arguments:
	buffer		<ByteArray> transformed data
	startIndex <Integer>	start of transform
	stopIndex	<Integer>	end of transform
	m			<ByteArray>	key stream data
	x			<Integer>	key state value
	y			<Integer>	key state value
	Return value:
	x@y - updated key state value
	 */
/*	Align in case the compiler identifies and generates vector instructions */

	/* CroquetPlugin>>#primitiveARC4Transform */
EXPORT(sqInt)
primitiveARC4Transform(void)
{
    unsigned char a;
    unsigned char b;
    unsigned char *buffer;
    sqInt bufOop;
    sqInt bufSize;
    sqInt i;
    unsigned char *m;
    unsigned char mask;
    sqInt mOop;
    sqInt ptOop;
    sqInt startIndex;
    sqInt stopIndex;
    sqInt x;
    sqInt xOop;
    sqInt y;
    sqInt yOop;

	if (!((methodArgumentCount()) == 6)) {
		return primitiveFail();
	}
	y = stackIntegerValue(0);
	x = stackIntegerValue(1);
	mOop = stackValue(2);
	stopIndex = stackIntegerValue(3);
	startIndex = stackIntegerValue(4);
	bufOop = stackValue(5);
	if (failed()) {
		return null;
	}
	if (!((isBytes(mOop))
		 && ((isBytes(bufOop))
		 && (((byteSizeOf(mOop)) == 0x100)
		 && ((startIndex > 0)
		 && ((startIndex <= ((bufSize = byteSizeOf(bufOop))))
		 && ((stopIndex >= startIndex)
		 && (stopIndex <= bufSize)))))))) {
		return primitiveFail();
	}
	m = firstIndexableField(mOop);
	buffer = firstIndexableField(bufOop);
	for (i = (startIndex - 1); i < stopIndex; i += 1) {
		x = (x + 1) & 0xFF;
		a = m[x];
		y = (y + a) & 0xFF;
		b = m[y];
		m[x] = b;
		m[y] = a;
		mask = m[(a + b) & 0xFF];
		buffer[i] = ((buffer[i]) ^ mask);
	}
	ptOop = instantiateClassindexableSize(classPoint(), 0);
#  if SPURVM
	xOop = positive32BitIntegerFor(x);
	yOop = positive32BitIntegerFor(y);
	if ((ptOop == null)
	 || ((xOop == null)
	 || (yOop == null))) {
		return primitiveFailFor(PrimErrNoMemory);
	}
	storePointerofObjectwithValue(0, ptOop, xOop);
	storePointerofObjectwithValue(1, ptOop, yOop);
#  else // SPURVM
	pushRemappableOop(ptOop);
	xOop = positive32BitIntegerFor(x);
	pushRemappableOop(xOop);
	yOop = positive32BitIntegerFor(y);
	xOop = popRemappableOop();
	ptOop = popRemappableOop();
	storePointerofObjectwithValue(0, ptOop, xOop);
	storePointerofObjectwithValue(1, ptOop, yOop);
#  endif // SPURVM
	return methodReturnValue(ptOop);
}


/*	Computes the determinant of the upper 3x3 of a Matrix4x4 */

	/* CroquetPlugin>>#primitiveDet3 */
EXPORT(sqInt)
primitiveDet3(void)
{
    double m11;
    double m12;
    double m13;
    double m21;
    double m22;
    double m23;
    double m31;
    double m32;
    double m33;
    float *src;
    sqInt srcOop;


	/* Load element vars using C version of Matrix4x4 storage, as 0-based, 1-dimensional array:
	   0 1 2 3
	   4 5 6 7
	   8 9 10 11
	    */
	srcOop = stackObjectValue(0);
	if (failed()) {
		return null;
	}
	src = ((float *) (firstIndexableField(srcOop)));
	m11 = src[0];
	m12 = src[1];
	m13 = src[2];
	m21 = src[4];
	m22 = src[5];
	m23 = src[6];
	m31 = src[8];
	m32 = src[9];
	m33 = src[10];
	return methodReturnFloat(((m11 * ((m22 * m33) - (m23 * m32))) + (m12 * ((m23 * m31) - (m21 * m33)))) + (m13 * ((m21 * m32) - (m22 * m31))));
}


/*	Primitive. Gather good random entropy from a system source. */

	/* CroquetPlugin>>#primitiveGatherEntropy */
EXPORT(sqInt)
primitiveGatherEntropy(void)
{
    sqInt bufOop;

	bufOop = stackValue(0);
	if (!((isBytes(bufOop))
		 && (ioGatherEntropy(firstIndexableField(bufOop), byteSizeOf(bufOop))))) {
		return primitiveFail();
	}
	return methodReturnBool(1);
}


/*	Primitive. Perform an inplace house holder matrix inversion */

	/* CroquetPlugin>>#primitiveInplaceHouseHolderInvert */
EXPORT(sqInt)
primitiveInplaceHouseHolderInvert(void)
{
    double beta;
    double d[4][4];
    sqInt i;
    sqInt j;
    sqInt k;
    double m[4][4];
    sqInt oop;
    sqInt r;
    float *rcvr;
    double s;
    double sigma;
    double sum;
    double x[4][4] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} };

	/* begin stackMatrix: */
	oop = stackValue(0);
	rcvr = ((isWords(oop))
	 && ((slotSizeOf(oop)) == 16)
		? ((float *) (firstIndexableField(oop)))
		: 0);
	if (!rcvr) {
		return primitiveFail();
	}
	for (i = 0; i <= 3; i += 1) {
		for (j = 0; j <= 3; j += 1) {
			(m[i])[j] = (rcvr[(i * 4) + j]);
		}
	}
	for (j = 0; j <= 3; j += 1) {
		sigma = 0.0;
		for (i = j; i <= 3; i += 1) {
			sigma += ((m[i])[j]) * ((m[i])[j]);
		}
		if (sigma < 1.0e-10) {
			return primitiveFail();
		}
		if (((m[j])[j]) < 0.0) {
			s = sqrt(sigma);
		}
		else {
			s = 0.0 - (sqrt(sigma));
		}
		for (r = 0; r <= 3; r += 1) {
			(d[j])[r] = s;
		}
		beta = 1.0 / ((s * ((m[j])[j])) - sigma);
		(m[j])[j] = (((m[j])[j]) - s);
		for (k = (j + 1); k <= 3; k += 1) {
			sum = 0.0;
			for (i = j; i <= 3; i += 1) {
				sum += ((m[i])[j]) * ((m[i])[k]);
			}
			sum = sum * beta;
			for (i = j; i <= 3; i += 1) {
				(m[i])[k] = (((m[i])[k]) + (((m[i])[j]) * sum));
			}
		}
		for (r = 0; r <= 3; r += 1) {
			sum = 0.0;
			for (i = j; i <= 3; i += 1) {
				sum += ((x[i])[r]) * ((m[i])[j]);
			}
			sum = sum * beta;
			for (i = j; i <= 3; i += 1) {
				(x[i])[r] = (((x[i])[r]) + (sum * ((m[i])[j])));
			}
		}
	}
	for (r = 0; r <= 3; r += 1) {
		for (i = 3; i >= 0; i += -1) {
			for (j = (i + 1); j <= 3; j += 1) {
				(x[i])[r] = (((x[i])[r]) - (((x[j])[r]) * ((m[i])[j])));
			}
			(x[i])[r] = (((x[i])[r]) / ((d[i])[r]));
		}
	}
	for (i = 0; i <= 3; i += 1) {
		for (j = 0; j <= 3; j += 1) {
			rcvr[(i * 4) + j] = (((float) ((x[i])[j])));
		}
	}
	return null;
}


/*	Computes the inverse of the Matrix4x4 receiver, using the 'classical
	adjoint' method,
	placing the results the the Matrix4x4 argument,
	
 */

	/* CroquetPlugin>>#primitiveInverseByAdjoint */
EXPORT(sqInt)
primitiveInverseByAdjoint(void)
{
    const int c11 = 0;
    const int c12 = 1;
    const int c13 = 2;
    const int c14 = 3;
    const int c21 = 4;
    const int c22 = 5;
    const int c23 = 6;
    const int c24 = 7;
    const int c31 = 8;
    const int c32 = 9;
    const int c33 = 10;
    const int c34 = 11;
    double det;
    float *dst;
    sqInt dstOop;
    double m11;
    double m12;
    double m13;
    double m21;
    double m22;
    double m23;
    double m31;
    double m32;
    double m33;
    float *src;
    sqInt srcOop;
    double x;
    double y;
    double z;


	/* then we need the following no-op to make Smalltalk shut up about vars not being initted. */
	srcOop = stackValue(1);
	dstOop = stackValue(0);
	if (failed()) {
		return null;
	}
	src = ((float *) (firstIndexableField(srcOop)));

	/* read in the source matrix 3x3, which contains the encoded rotation and scale factors */
	dst = ((float *) (firstIndexableField(dstOop)));
	m11 = src[c11];
	m12 = src[c12];
	m13 = src[c13];
	m21 = src[c21];
	m22 = src[c22];
	m23 = src[c23];
	m31 = src[c31];
	m32 = src[c32];

	/* read in the source translation vector */
	m33 = src[c33];
	x = src[c14];
	y = src[c24];

	/* do the actual work */
	/* first, compute the determinant of the upper 3x3 of the source */
	z = src[c34];

	/* Compute the classical adjunct of the source, and divide by the source determinant
	   storing in the destination.  adjoint = transpose of cofactors, so we'll transpose as we store. */
	det = ((m11 * ((m22 * m33) - (m23 * m32))) + (m12 * ((m23 * m31) - (m21 * m33)))) + (m13 * ((m21 * m32) - (m22 * m31)));

	/* let's make div by det a multiply */
	det = 1 / det;
	dst[c11] = (((m22 * m33) - (m23 * m32)) * det);
	dst[c21] = ((0.0 - ((m21 * m33) - (m23 * m31))) * det);
	dst[c31] = (((m21 * m32) - (m22 * m31)) * det);
	dst[c12] = ((0.0 - ((m12 * m33) - (m13 * m32))) * det);
	dst[c22] = (((m11 * m33) - (m13 * m31)) * det);
	dst[c32] = ((0.0 - ((m11 * m32) - (m12 * m31))) * det);
	dst[c13] = (((m12 * m23) - (m13 * m22)) * det);
	dst[c23] = ((0.0 - ((m11 * m23) - (m13 * m21))) * det);
	dst[c33] = (((m11 * m22) - (m12 * m21)) * det);
	m11 = dst[c11];
	m12 = dst[c12];
	m13 = dst[c13];
	m21 = dst[c21];
	m22 = dst[c22];
	m23 = dst[c23];
	m31 = dst[c31];
	m32 = dst[c32];
	m33 = dst[c33];
	dst[c14] = (0.0 - (((x * m11) + (y * m12)) + (z * m13)));
	dst[c24] = (0.0 - (((x * m21) + (y * m22)) + (z * m23)));
	dst[c34] = (0.0 - (((x * m31) + (y * m32)) + (z * m33)));
	return methodReturnValue(dstOop);
}


/*	Perform an MD5 transform of input */
/*	Align in case the compiler identifies and generates vector instructions */

	/* CroquetPlugin>>#primitiveMD5Transform */
EXPORT(sqInt)
primitiveMD5Transform(void)
{
    sqInt bufOop;
    sqInt hashOop;

	hashOop = stackValue(0);
	bufOop = stackValue(1);
	if (!((isWords(hashOop))
		 && (((slotSizeOf(hashOop)) == 4)
		 && ((isWords(bufOop))
		 && ((slotSizeOf(bufOop)) == 16))))) {
		return primitiveFail();
	}
	MD5Transform(firstIndexableField(hashOop), firstIndexableField(bufOop));
	return methodReturnValue(bufOop);
}


/*	Given a list of integer indices for rendering a triangle-mesh in
	indexed-triangles mode, reorganize the indices in-place to provide better
	vertex cache locality.
	We use Tom Forsyth's algorithm:
	http://home.comcast.net/~tom_forsyth/papers/fast_vert_cache_opt.html
	... and the MIT-licensed implementation by Michael Georgoulpoulos at:
	http://code.google.com/p/vcacne/ */

	/* CroquetPlugin>>#primitiveOptimizeVertexIndicesForCacheLocality */
EXPORT(sqInt)
primitiveOptimizeVertexIndicesForCacheLocality(void)
{
    sqInt byteSize;
    sqInt indicesOop;
    sqInt triCount;

	indicesOop = stackValue(0);
	if (!(isWords(indicesOop))) {
		return primitiveFail();
	}
	byteSize = byteSizeOf(indicesOop);
	triCount = byteSize / 12;
	if (!((triCount * 12) == byteSize)) {
		return primitiveFail();
	}
	if ((optimizeVertexIndices(firstIndexableField(indicesOop), triCount)) != 0) {
		return primitiveFail();
	}
	return methodReturnReceiver();
}

	/* CroquetPlugin>>#primitiveOrthoNormInverseMatrix */
EXPORT(sqInt)
primitiveOrthoNormInverseMatrix(void)
{
    float *dst;
    sqInt dstOop;
    double rx;
    double ry;
    double rz;
    float *src;
    sqInt srcOop;
    double x;
    double y;
    double z;

	srcOop = stackValue(0);
	if (!((isWords(srcOop))
		 && ((slotSizeOf(srcOop)) == 16))) {
		return primitiveFail();
	}
	dstOop = cloneObject(srcOop);
	if (dstOop == 0) {
		return primitiveFail();
	}
#  if !SPURVM
	srcOop = stackValue(0);
#  endif
	src = ((float *) (firstIndexableField(srcOop)));

	/* Transpose upper 3x3 matrix */
	/* dst at: 0 put: (src at: 0). */
	dst = ((float *) (firstIndexableField(dstOop)));
	dst[1] = (src[4]);
	dst[2] = (src[8]);
	dst[4] = (src[1]);
	dst[6] = (src[9]);
	dst[8] = (src[2]);
	dst[9] = (src[6]);
	x = src[3];
	y = src[7];
	z = src[11];
	rx = ((x * (dst[0])) + (y * (dst[1]))) + (z * (dst[2]));
	ry = ((x * (dst[4])) + (y * (dst[5]))) + (z * (dst[6]));
	rz = ((x * (dst[8])) + (y * (dst[9]))) + (z * (dst[10]));
	dst[3] = (0.0 - rx);
	dst[7] = (0.0 - ry);
	dst[11] = (0.0 - rz);
	return methodReturnValue(dstOop);
}

	/* CroquetPlugin>>#primitiveTransformDirection */
EXPORT(sqInt)
primitiveTransformDirection(void)
{
    float *matrix;
    sqInt oop;
    double rx;
    double ry;
    double rz;
    sqInt v3Oop;
    float *vertex;
    double x;
    double y;
    double z;

	/* begin stackMatrix: */
	oop = stackValue(1);
	matrix = ((isWords(oop))
	 && ((slotSizeOf(oop)) == 16)
		? ((float *) (firstIndexableField(oop)))
		: 0);
	v3Oop = stackValue(0);
	if (!((matrix != null)
		 && ((isWords(v3Oop))
		 && ((slotSizeOf(v3Oop)) == 3)))) {
		return primitiveFail();
	}
	vertex = ((float *) (firstIndexableField(v3Oop)));
	x = vertex[0];
	y = vertex[1];
	z = vertex[2];
	rx = ((x * (matrix[0])) + (y * (matrix[1]))) + (z * (matrix[2]));
	ry = ((x * (matrix[4])) + (y * (matrix[5]))) + (z * (matrix[6]));
	rz = ((x * (matrix[8])) + (y * (matrix[9]))) + (z * (matrix[10]));
	v3Oop = cloneObject(v3Oop);
	if (v3Oop == 0) {
		return primitiveFailFor(PrimErrNoMemory);
	}
	vertex = ((float *) (firstIndexableField(v3Oop)));
	vertex[0] = rx;
	vertex[1] = ry;
	vertex[2] = rz;
	return methodReturnValue(v3Oop);
}


/*	Transform two matrices into the third */

	/* CroquetPlugin>>#primitiveTransformMatrixWithInto */
EXPORT(sqInt)
primitiveTransformMatrixWithInto(void)
{
    double c1;
    double c2;
    double c3;
    double c4;
    sqInt i;
    float *m1;
    float *m11;
    float *m2;
    float *m21;
    float *m3;
    float *m31;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;

	/* begin stackMatrix: */
	oop = stackValue(0);
	m3 = ((isWords(oop))
	 && ((slotSizeOf(oop)) == 16)
		? ((float *) (firstIndexableField(oop)))
		: 0);
	/* begin stackMatrix: */
	oop1 = stackValue(1);
	m2 = ((isWords(oop1))
	 && ((slotSizeOf(oop1)) == 16)
		? ((float *) (firstIndexableField(oop1)))
		: 0);
	/* begin stackMatrix: */
	oop2 = stackValue(2);
	m1 = ((isWords(oop2))
	 && ((slotSizeOf(oop2)) == 16)
		? ((float *) (firstIndexableField(oop2)))
		: 0);
	if ((m1 == null)
	 || ((m2 == null)
	 || ((m3 == null)
	 || (m2 == m3)))) {
		return primitiveFail();
	}
	/* begin transformMatrix:with:into: */
	m11 = ((float *) m1);
	m21 = ((float *) m2);
	m31 = ((float *) m3);
	for (i = 0; i <= 3; i += 1) {

		/* Compute next row */
		c1 = ((((m11[0]) * (m21[0])) + ((m11[1]) * (m21[4]))) + ((m11[2]) * (m21[8]))) + ((m11[3]) * (m21[12]));
		c2 = ((((m11[0]) * (m21[1])) + ((m11[1]) * (m21[5]))) + ((m11[2]) * (m21[9]))) + ((m11[3]) * (m21[13]));
		c3 = ((((m11[0]) * (m21[2])) + ((m11[1]) * (m21[6]))) + ((m11[2]) * (m21[10]))) + ((m11[3]) * (m21[14]));

		/* Store result */
		c4 = ((((m11[0]) * (m21[3])) + ((m11[1]) * (m21[7]))) + ((m11[2]) * (m21[11]))) + ((m11[3]) * (m21[15]));
		m31[0] = c1;
		m31[1] = c2;
		m31[2] = c3;
		m31[3] = c4;
		m11 += 4;
		m31 += 4;
	}
	return methodReturnReceiver();
}

	/* CroquetPlugin>>#primitiveTransformVector3 */
EXPORT(sqInt)
primitiveTransformVector3(void)
{
    float *matrix;
    sqInt oop;
    double rw;
    double rx;
    double ry;
    double rz;
    sqInt v3Oop;
    float *vertex;
    double x;
    double y;
    double z;

	/* begin stackMatrix: */
	oop = stackValue(1);
	matrix = ((isWords(oop))
	 && ((slotSizeOf(oop)) == 16)
		? ((float *) (firstIndexableField(oop)))
		: 0);
	v3Oop = stackValue(0);
	if (!((matrix != null)
		 && ((isWords(v3Oop))
		 && ((slotSizeOf(v3Oop)) == 3)))) {
		return primitiveFail();
	}
	vertex = ((float *) (firstIndexableField(v3Oop)));
	x = vertex[0];
	y = vertex[1];
	z = vertex[2];
	rx = (((x * (matrix[0])) + (y * (matrix[1]))) + (z * (matrix[2]))) + (matrix[3]);
	ry = (((x * (matrix[4])) + (y * (matrix[5]))) + (z * (matrix[6]))) + (matrix[7]);
	rz = (((x * (matrix[8])) + (y * (matrix[9]))) + (z * (matrix[10]))) + (matrix[11]);
	rw = (((x * (matrix[12])) + (y * (matrix[13]))) + (z * (matrix[14]))) + (matrix[15]);
	v3Oop = cloneObject(v3Oop);
	if (v3Oop == 0) {
		return primitiveFailFor(PrimErrNoMemory);
	}
	vertex = ((float *) (firstIndexableField(v3Oop)));
	if (rw == 1.0) {
		vertex[0] = rx;
		vertex[1] = ry;
		vertex[2] = rz;
	}
	else {
		if (rw == 0.0) {
			rw = 0.0;
		}
		else {
			rw = 1.0 / rw;
		}
		vertex[0] = (rx * rw);
		vertex[1] = (ry * rw);
		vertex[2] = (rz * rw);
	}
	return methodReturnValue(v3Oop);
}

	/* CroquetPlugin>>#primitiveTransposeMatrix */
EXPORT(sqInt)
primitiveTransposeMatrix(void)
{
    float *dst;
    sqInt dstOop;
    float *src;
    sqInt srcOop;

	if (!((methodArgumentCount()) == 0)) {
		return primitiveFail();
	}
	srcOop = stackObjectValue(0);
	if (failed()) {
		return null;
	}
	if (!((isWords(srcOop))
		 && ((slotSizeOf(srcOop)) == 16))) {
		return primitiveFail();
	}

	/* reload srcOop in case of GC */
	dstOop = cloneObject(srcOop);
	srcOop = stackObjectValue(0);
	src = firstIndexableField(srcOop);

	/* dst at: 0 put: (src at: 0). */
	dst = firstIndexableField(dstOop);
	dst[1] = (src[4]);
	dst[2] = (src[8]);
	dst[3] = (src[12]);
	dst[4] = (src[1]);
	dst[6] = (src[9]);
	dst[7] = (src[13]);
	dst[8] = (src[2]);
	dst[9] = (src[6]);
	dst[11] = (src[14]);
	dst[12] = (src[3]);
	dst[13] = (src[7]);
	dst[14] = (src[11]);
	pop(1);
	return push(dstOop);
}


/*	Primitive. Answer whether an AABB intersects with a given triangle */

	/* CroquetPlugin>>#primitiveTriBoxIntersects */
EXPORT(sqInt)
primitiveTriBoxIntersects(void)
{
    float *maxCorner;
    float *minCorner;
    sqInt oop;
    sqInt oop1;
    sqInt oop2;
    sqInt oop3;
    sqInt oop4;
    sqInt result;
    float *v0;
    float *v1;
    float *v2;

	/* begin stackVector3: */
	oop = stackValue(0);
	v2 = ((isWords(oop))
	 && ((slotSizeOf(oop)) == 3)
		? ((float *) (firstIndexableField(oop)))
		: 0);
	/* begin stackVector3: */
	oop1 = stackValue(1);
	v1 = ((isWords(oop1))
	 && ((slotSizeOf(oop1)) == 3)
		? ((float *) (firstIndexableField(oop1)))
		: 0);
	/* begin stackVector3: */
	oop2 = stackValue(2);
	v0 = ((isWords(oop2))
	 && ((slotSizeOf(oop2)) == 3)
		? ((float *) (firstIndexableField(oop2)))
		: 0);
	/* begin stackVector3: */
	oop3 = stackValue(3);
	maxCorner = ((isWords(oop3))
	 && ((slotSizeOf(oop3)) == 3)
		? ((float *) (firstIndexableField(oop3)))
		: 0);
	/* begin stackVector3: */
	oop4 = stackValue(4);
	minCorner = ((isWords(oop4))
	 && ((slotSizeOf(oop4)) == 3)
		? ((float *) (firstIndexableField(oop4)))
		: 0);
	if ((v0 == null)
	 || ((v1 == null)
	 || ((v2 == null)
	 || ((maxCorner == null)
	 || (minCorner == null))))) {
		return primitiveFail();
	}
	result = triBoxOverlap(minCorner, maxCorner, v0, v1, v2);
	if (result < 0) {
		return primitiveFail();
	}
	return methodReturnBool(result > 0);
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine *anInterpreter)
{
    sqInt ok;


	/* This may seem tautological, but in a real plugin it checks that the VM provides
	   the version the plugin was compiled against which is the version the plugin expects. */
	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		byteSizeOf = interpreterProxy->byteSizeOf;
		classPoint = interpreterProxy->classPoint;
		cloneObject = interpreterProxy->cloneObject;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		isBytes = interpreterProxy->isBytes;
		isWords = interpreterProxy->isWords;
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		methodReturnBool = interpreterProxy->methodReturnBool;
		methodReturnFloat = interpreterProxy->methodReturnFloat;
		methodReturnReceiver = interpreterProxy->methodReturnReceiver;
		methodReturnValue = interpreterProxy->methodReturnValue;
		pop = interpreterProxy->pop;
		popRemappableOop = interpreterProxy->popRemappableOop;
		positive32BitIntegerFor = interpreterProxy->positive32BitIntegerFor;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		push = interpreterProxy->push;
		pushRemappableOop = interpreterProxy->pushRemappableOop;
		slotSizeOf = interpreterProxy->slotSizeOf;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackObjectValue = interpreterProxy->stackObjectValue;
		stackValue = interpreterProxy->stackValue;
		storePointerofObjectwithValue = interpreterProxy->storePointerofObjectwithValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


/*	Transform src with arg into dst.
	It is allowed that src == dst but not arg == dst */

	/* CroquetPlugin>>#transformMatrix:with:into: */
static sqInt
transformMatrixwithinto(float *src, float *arg, float *dst)
{
    double c1;
    double c2;
    double c3;
    double c4;
    sqInt i;
    float *m1;
    float *m2;
    float *m3;

	m1 = ((float *) src);
	m2 = ((float *) arg);
	m3 = ((float *) dst);
	for (i = 0; i <= 3; i += 1) {

		/* Compute next row */
		c1 = ((((m1[0]) * (m2[0])) + ((m1[1]) * (m2[4]))) + ((m1[2]) * (m2[8]))) + ((m1[3]) * (m2[12]));
		c2 = ((((m1[0]) * (m2[1])) + ((m1[1]) * (m2[5]))) + ((m1[2]) * (m2[9]))) + ((m1[3]) * (m2[13]));
		c3 = ((((m1[0]) * (m2[2])) + ((m1[1]) * (m2[6]))) + ((m1[2]) * (m2[10]))) + ((m1[3]) * (m2[14]));

		/* Store result */
		c4 = ((((m1[0]) * (m2[3])) + ((m1[1]) * (m2[7]))) + ((m1[2]) * (m2[11]))) + ((m1[3]) * (m2[15]));
		m3[0] = c1;
		m3[1] = c2;
		m3[2] = c3;
		m3[3] = c4;
		m1 += 4;
		m3 += 4;
	}
	return null;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "CroquetPlugin";
void* CroquetPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveAdj3\000\001\003", (void*)primitiveAdj3},
	{(void*)_m, "primitiveARC4Transform\000\001\003", (void*)primitiveARC4Transform},
	{(void*)_m, "primitiveDet3\000\001\003", (void*)primitiveDet3},
	{(void*)_m, "primitiveGatherEntropy\000\001\000", (void*)primitiveGatherEntropy},
	{(void*)_m, "primitiveInplaceHouseHolderInvert\000\377\003", (void*)primitiveInplaceHouseHolderInvert},
	{(void*)_m, "primitiveInverseByAdjoint\000\001\003", (void*)primitiveInverseByAdjoint},
	{(void*)_m, "primitiveMD5Transform\000\001\003", (void*)primitiveMD5Transform},
	{(void*)_m, "primitiveOptimizeVertexIndicesForCacheLocality\000\001\000", (void*)primitiveOptimizeVertexIndicesForCacheLocality},
	{(void*)_m, "primitiveOrthoNormInverseMatrix\000\001\003", (void*)primitiveOrthoNormInverseMatrix},
	{(void*)_m, "primitiveTransformDirection\000\001\003", (void*)primitiveTransformDirection},
	{(void*)_m, "primitiveTransformMatrixWithInto\000\377\003", (void*)primitiveTransformMatrixWithInto},
	{(void*)_m, "primitiveTransformVector3\000\001\003", (void*)primitiveTransformVector3},
	{(void*)_m, "primitiveTransposeMatrix\000\001\000", (void*)primitiveTransposeMatrix},
	{(void*)_m, "primitiveTriBoxIntersects\000\377\003", (void*)primitiveTriBoxIntersects},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else // ifdef SQ_BUILTIN_PLUGIN

#if SPURVM
EXPORT(signed short) primitiveAdj3Metadata = 259;
EXPORT(signed short) primitiveARC4TransformMetadata = 259;
EXPORT(signed short) primitiveDet3Metadata = 259;
EXPORT(signed short) primitiveGatherEntropyMetadata = 0x100;
EXPORT(signed short) primitiveInplaceHouseHolderInvertMetadata = -253;
EXPORT(signed short) primitiveInverseByAdjointMetadata = 259;
EXPORT(signed short) primitiveMD5TransformMetadata = 259;
EXPORT(signed short) primitiveOptimizeVertexIndicesForCacheLocalityMetadata = 0x100;
EXPORT(signed short) primitiveOrthoNormInverseMatrixMetadata = 259;
EXPORT(signed short) primitiveTransformDirectionMetadata = 259;
EXPORT(signed short) primitiveTransformMatrixWithIntoMetadata = -253;
EXPORT(signed short) primitiveTransformVector3Metadata = 259;
EXPORT(signed short) primitiveTransposeMatrixMetadata = 0x100;
EXPORT(signed short) primitiveTriBoxIntersectsMetadata = -253;
#endif // SPURVM

#endif // ifdef SQ_BUILTIN_PLUGIN
