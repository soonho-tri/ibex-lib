# -*- python -*-
# This file contains rules for Bazel; see https://bazel.io/ .

# We build CLP by shelling out to autotools.

# A prefix-string for genrule cmd attributes, which uses the Kythe cdexec tool,
# in quiet mode, to execute in the genrule output directory.
CDEXEC = "$(location @//tools/third_party/kythe/tools/cdexec:cdexec) -q $(@D)"

# We run autotools in a genrule, and only files explicitly identified as outputs
# of that genrule can be made available to other rules. Therefore, we need a
# list of every file in the CLP install.
# See https://github.com/bazelbuild/bazel/issues/281.

CLP_HDRS = [
    "include/coin/CoinOslFactorization.hpp",
    "include/coin/ClpCholeskyBase.hpp",
    "include/coin/ClpGubMatrix.hpp",
    "include/coin/OsiBranchingObject.hpp",
    "include/coin/ClpPlusMinusOneMatrix.hpp",
    "include/coin/ClpSimplexPrimal.hpp",
    "include/coin/CbcOrClpParam.hpp",
    "include/coin/OsiAuxInfo.hpp",
    "include/coin/Clp_C_Interface.h",
    "include/coin/CoinPresolveImpliedFree.hpp",
    "include/coin/ClpDummyMatrix.hpp",
    "include/coin/CoinModel.hpp",
    "include/coin/ClpSimplexNonlinear.hpp",
    "include/coin/CoinHelperFunctions.hpp",
    "include/coin/CoinFileIO.hpp",
    "include/coin/CoinMessageHandler.hpp",
    "include/coin/ClpInterior.hpp",
    "include/coin/ClpSimplexDual.hpp",
    "include/coin/CoinPresolveIsolated.hpp",
    "include/coin/CoinPackedVectorBase.hpp",
    "include/coin/ClpEventHandler.hpp",
    "include/coin/CoinPresolveUseless.hpp",
    "include/coin/OsiColCut.hpp",
    "include/coin/CoinWarmStart.hpp",
    "include/coin/CoinPresolveTighten.hpp",
    "include/coin/OsiUnitTests.hpp",
    "include/coin/CoinSignal.hpp",
    "include/coin/ClpPackedMatrix.hpp",
    "include/coin/ClpMessage.hpp",
    "include/coin/ClpConstraintQuadratic.hpp",
    "include/coin/CoinWarmStartDual.hpp",
    "include/coin/ClpDualRowDantzig.hpp",
    "include/coin/CoinSnapshot.hpp",
    "include/coin/ClpMatrixBase.hpp",
    "include/coin/ClpPrimalColumnPivot.hpp",
    "include/coin/ClpDualRowSteepest.hpp",
    "include/coin/CoinWarmStartBasis.hpp",
    "include/coin/OsiConfig.h",
    "include/coin/OsiSolverBranch.hpp",
    "include/coin/CoinShallowPackedVector.hpp",
    "include/coin/CoinPackedVector.hpp",
    "include/coin/CoinBuild.hpp",
    "include/coin/OsiCut.hpp",
    "include/coin/CoinPresolvePsdebug.hpp",
    "include/coin/ClpModel.hpp",
    "include/coin/ClpPdcoBase.hpp",
    "include/coin/CoinTime.hpp",
    "include/coin/OsiSolverInterface.hpp",
    "include/coin/CoinLpIO.hpp",
    "include/coin/CoinAlloc.hpp",
    "include/coin/CoinPresolveFixed.hpp",
    "include/coin/CoinPresolveDoubleton.hpp",
    "include/coin/CoinMpsIO.hpp",
    "include/coin/CoinDistance.hpp",
    "include/coin/CoinSmartPtr.hpp",
    "include/coin/ClpConfig.h",
    "include/coin/ClpLinearObjective.hpp",
    "include/coin/ClpParameters.hpp",
    "include/coin/OsiPresolve.hpp",
    "include/coin/CoinModelUseful.hpp",
    "include/coin/OsiRowCut.hpp",
    "include/coin/ClpPresolve.hpp",
    "include/coin/CoinPresolveDual.hpp",
    "include/coin/ClpNonLinearCost.hpp",
    "include/coin/CoinPresolveSingleton.hpp",
    "include/coin/OsiClpSolverInterface.hpp",
    "include/coin/ClpNetworkMatrix.hpp",
    "include/coin/CoinTypes.hpp",
    "include/coin/CoinFloatEqual.hpp",
    "include/coin/ClpQuadraticObjective.hpp",
    "include/coin/CoinDenseVector.hpp",
    "include/coin/ClpNode.hpp",
    "include/coin/OsiRowCutDebugger.hpp",
    "include/coin/ClpPrimalColumnDantzig.hpp",
    "include/coin/ClpGubDynamicMatrix.hpp",
    "include/coin/CoinPresolveZeros.hpp",
    "include/coin/OsiSolverParameters.hpp",
    "include/coin/ClpDynamicExampleMatrix.hpp",
    "include/coin/ClpSolve.hpp",
    "include/coin/CoinError.hpp",
    "include/coin/CbcOrClpParam.cpp",
    "include/coin/ClpSimplex.hpp",
    "include/coin/CoinPresolveMatrix.hpp",
    "include/coin/CoinPresolveTripleton.hpp",
    "include/coin/CoinUtility.hpp",
    "include/coin/ClpSimplexOther.hpp",
    "include/coin/CoinWarmStartPrimalDual.hpp",
    "include/coin/Coin_C_defines.h",
    "include/coin/CoinDenseFactorization.hpp",
    "include/coin/CoinIndexedVector.hpp",
    "include/coin/CoinFactorization.hpp",
    "include/coin/CoinPragma.hpp",
    "include/coin/CoinSort.hpp",
    "include/coin/ClpConstraint.hpp",
    "include/coin/CoinParam.hpp",
    "include/coin/CoinRational.hpp",
    "include/coin/CoinFinite.hpp",
    "include/coin/OsiCuts.hpp",
    "include/coin/CoinPresolveMonitor.hpp",
    "include/coin/CoinStructuredModel.hpp",
    "include/coin/CoinPackedMatrix.hpp",
    "include/coin/CoinSearchTree.hpp",
    "include/coin/OsiCollections.hpp",
    "include/coin/Idiot.hpp",
    "include/coin/ClpDynamicMatrix.hpp",
    "include/coin/OsiChooseVariable.hpp",
    "include/coin/ClpFactorization.hpp",
    "include/coin/ClpDualRowPivot.hpp",
    "include/coin/CoinWarmStartVector.hpp",
    "include/coin/ClpConstraintLinear.hpp",
    "include/coin/CoinPresolveForcing.hpp",
    "include/coin/CoinPresolveDupcol.hpp",
    "include/coin/ClpPrimalColumnSteepest.hpp",
    "include/coin/CoinSimpFactorization.hpp",
    "include/coin/CoinMessage.hpp",
    "include/coin/ClpObjective.hpp",
    "include/coin/CoinPresolveEmpty.hpp",
    "include/coin/CoinPresolveSubst.hpp",
    "include/coin/CoinUtilsConfig.h",
    "include/coin/ClpCholeskyDense.hpp",
]

CLP_LIBS = [
    "lib/libClp.a",
    "lib/libCoinUtils.a",
    "lib/libOsi.a",
    "lib/libClpSolver.a",
    "lib/libOsiCommonTests.a",
    "lib/libOsiClp.a",
]

# Invokes ./configure, make, and make install to build CLP. We arbitrarily
# allow make to use a number of cores equal to half the number of available
# cores, rounded up.
#
# We emit static libraries because dynamic libraries would have different names
# on OS X and on Linux, and Bazel genrules don't allow platform-dependent outs.
# https://github.com/bazelbuild/bazel/issues/281
HALF_THE_CORES = "$$[($$(getconf _NPROCESSORS_ONLN)+1)/2]"

LOG = " 2>> clp.log"

PRINT_ERRORS = (
    "echo \"***CLP Build stderr***\"" +
    " && cat clp.log" +
    " && echo \"***CLP Build config.log***\"" +
    " && find -L . -name config.log | xargs cat"
)

BUILD_CLP_CMD = (
    "(" + CDEXEC + " `pwd`/external/clp/configure --enable-static --with-pic --disable-zlib --disable-bzlib --without-blas --without-lapack" + LOG +
    " && " + CDEXEC + " make -j " + HALF_THE_CORES + LOG +
    " && " + CDEXEC + " make test" + LOG +
    " && " + CDEXEC + " make install" + LOG +
    ") || (" + PRINT_ERRORS + " && false)"
)

genrule(
    name = "build_with_autotools",
    srcs = glob(["**/*"]),
    outs = CLP_HDRS + CLP_LIBS,
    cmd = BUILD_CLP_CMD,
    tools = ["@//tools/third_party/kythe/tools/cdexec:cdexec"],
    visibility = ["//visibility:private"],
)

cc_library(
    name = "clp",
    srcs = CLP_LIBS,
    hdrs = CLP_HDRS,
    includes = [
        "include",
    ],
    linkstatic = 1,
    visibility = ["//visibility:public"],
    alwayslink = 1,
)
