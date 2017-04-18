# -*- python -*-
# This file contains rules for Bazel; see https://bazel.io/ .

# We build filibxx by shelling out to autotools.

# A prefix-string for genrule cmd attributes, which uses the Kythe cdexec tool,
# in quiet mode, to execute in the genrule output directory.
CDEXEC = "$(location @//tools/third_party/kythe/tools/cdexec:cdexec) -q $(@D)"
CDEXEC_WITH_DIR = "$(location @//tools/third_party/kythe/tools/cdexec:cdexec) -q "

# We run autotools in a genrule, and only files explicitly identified as outputs
# of that genrule can be made available to other rules. Therefore, we need a
# list of every file in the filibxx install.
# See https://github.com/bazelbuild/bazel/issues/281.

FILIBXX_HDRS = [
    "include/fp_traits/fp_traits.hpp",
    "include/fp_traits/fp_traits_base_double.icc",
    "include/fp_traits/fp_traits_base_float.icc",
    "include/fp_traits/fp_traits_double.hpp",
    "include/fp_traits/fp_traits_double_generic_multiplicative.icc",
    "include/fp_traits/fp_traits_double_generic_native_directed.icc",
    "include/fp_traits/fp_traits_double_generic_native_onesided_global.icc",
    "include/fp_traits/fp_traits_double_generic_native_switched.icc",
    "include/fp_traits/fp_traits_double_generic_no_rounding.icc",
    "include/fp_traits/fp_traits_double_generic_pred_succ_rounding.icc",
    "include/fp_traits/fp_traits_double_sse_multiplicative.icc",
    "include/fp_traits/fp_traits_double_sse_native_directed.icc",
    "include/fp_traits/fp_traits_double_sse_native_onesided_global.icc",
    "include/fp_traits/fp_traits_double_sse_native_switched.icc",
    "include/fp_traits/fp_traits_double_sse_no_rounding.icc",
    "include/fp_traits/fp_traits_double_sse_pred_succ_rounding.icc",
    "include/fp_traits/fp_traits_double_x87_multiplicative.icc",
    "include/fp_traits/fp_traits_double_x87_native_directed.icc",
    "include/fp_traits/fp_traits_double_x87_native_onesided_global.icc",
    "include/fp_traits/fp_traits_double_x87_native_switched.icc",
    "include/fp_traits/fp_traits_double_x87_no_rounding.icc",
    "include/fp_traits/fp_traits_double_x87_pred_succ_rounding.icc",
    "include/fp_traits/fp_traits_float.hpp",
    "include/fp_traits/fp_traits_float_generic_multiplicative.icc",
    "include/fp_traits/fp_traits_float_generic_native_directed.icc",
    "include/fp_traits/fp_traits_float_generic_native_onesided_global.icc",
    "include/fp_traits/fp_traits_float_generic_native_switched.icc",
    "include/fp_traits/fp_traits_float_generic_no_rounding.icc",
    "include/fp_traits/fp_traits_float_sse_multiplicative.icc",
    "include/fp_traits/fp_traits_float_sse_native_directed.icc",
    "include/fp_traits/fp_traits_float_sse_native_onesided_global.icc",
    "include/fp_traits/fp_traits_float_sse_native_switched.icc",
    "include/fp_traits/fp_traits_float_sse_no_rounding.icc",
    "include/fp_traits/fp_traits_float_x87_multiplicative.icc",
    "include/fp_traits/fp_traits_float_x87_native_directed.icc",
    "include/fp_traits/fp_traits_float_x87_native_onesided_global.icc",
    "include/fp_traits/fp_traits_float_x87_native_switched.icc",
    "include/fp_traits/fp_traits_float_x87_no_rounding.icc",
    "include/fp_traits/fp_traits_sse_const.hpp",
    "include/fp_traits/fp_traits_x87_const.hpp",
    "include/ieee/primitive.hpp",
    "include/interval/filib.hpp",
    "include/interval/interval.hpp",
    "include/interval/interval.icc",
    "include/interval/interval_arith.icc",
    "include/interval/interval_fo.hpp",
    "include/interval/stdfun/filib_consts.hpp",
    "include/interval/stdfun/filib_tools.icc",
    "include/interval/stdfun/interval/acos.icc",
    "include/interval/stdfun/interval/acosh.icc",
    "include/interval/stdfun/interval/acot.icc",
    "include/interval/stdfun/interval/acoth.icc",
    "include/interval/stdfun/interval/asin.icc",
    "include/interval/stdfun/interval/asinh.icc",
    "include/interval/stdfun/interval/atan.icc",
    "include/interval/stdfun/interval/atanh.icc",
    "include/interval/stdfun/interval/cos.icc",
    "include/interval/stdfun/interval/cosh.icc",
    "include/interval/stdfun/interval/cot.icc",
    "include/interval/stdfun/interval/coth.icc",
    "include/interval/stdfun/interval/exp.icc",
    "include/interval/stdfun/interval/exp10.icc",
    "include/interval/stdfun/interval/exp2.icc",
    "include/interval/stdfun/interval/expm1.icc",
    "include/interval/stdfun/interval/log.icc",
    "include/interval/stdfun/interval/log10.icc",
    "include/interval/stdfun/interval/log1p.icc",
    "include/interval/stdfun/interval/log2.icc",
    "include/interval/stdfun/interval/pow.icc",
    "include/interval/stdfun/interval/sin.icc",
    "include/interval/stdfun/interval/sinh.icc",
    "include/interval/stdfun/interval/sqr.icc",
    "include/interval/stdfun/interval/sqrt.icc",
    "include/interval/stdfun/interval/tan.icc",
    "include/interval/stdfun/interval/tanh.icc",
    "include/interval/stdfun/point/q_acos.icc",
    "include/interval/stdfun/point/q_acot.icc",
    "include/interval/stdfun/point/q_acsh.icc",
    "include/interval/stdfun/point/q_acth.icc",
    "include/interval/stdfun/point/q_asin.icc",
    "include/interval/stdfun/point/q_asnh.icc",
    "include/interval/stdfun/point/q_atan.icc",
    "include/interval/stdfun/point/q_atn1.icc",
    "include/interval/stdfun/point/q_atnh.icc",
    "include/interval/stdfun/point/q_cos.icc",
    "include/interval/stdfun/point/q_cos1.icc",
    "include/interval/stdfun/point/q_cosh.icc",
    "include/interval/stdfun/point/q_cot.icc",
    "include/interval/stdfun/point/q_coth.icc",
    "include/interval/stdfun/point/q_cth1.icc",
    "include/interval/stdfun/point/q_ep1.icc",
    "include/interval/stdfun/point/q_epm1.icc",
    "include/interval/stdfun/point/q_errm.icc",
    "include/interval/stdfun/point/q_ex10.icc",
    "include/interval/stdfun/point/q_exp.icc",
    "include/interval/stdfun/point/q_exp2.icc",
    "include/interval/stdfun/point/q_expm.icc",
    "include/interval/stdfun/point/q_lg10.icc",
    "include/interval/stdfun/point/q_log.icc",
    "include/interval/stdfun/point/q_log1.icc",
    "include/interval/stdfun/point/q_log2.icc",
    "include/interval/stdfun/point/q_rtrg.icc",
    "include/interval/stdfun/point/q_sin.icc",
    "include/interval/stdfun/point/q_sin1.icc",
    "include/interval/stdfun/point/q_sinh.icc",
    "include/interval/stdfun/point/q_sqr.icc",
    "include/interval/stdfun/point/q_sqrt.icc",
    "include/interval/stdfun/point/q_tan.icc",
    "include/interval/stdfun/point/q_tanh.icc",
    "include/interval/tools.icc",
    "include/rounding_control/rounding_control.hpp",
    "include/rounding_control/rounding_control_config.hpp",
    "include/rounding_control/rounding_control_double.hpp",
    "include/rounding_control/rounding_control_double_asmmsvci386.icc",
    "include/rounding_control/rounding_control_double_asmsparc.icc",
    "include/rounding_control/rounding_control_double_iso9x.icc",
    "include/rounding_control/rounding_control_double_void.icc",
    "include/rounding_control/rounding_control_float.hpp",
    "include/rounding_control/rounding_control_float_asmmsvci386.icc",
    "include/rounding_control/rounding_control_float_asmsparc.icc",
    "include/rounding_control/rounding_control_float_iso9x.icc",
    "include/rounding_control/rounding_control_float_void.icc",
    "include/rounding_control/rounding_control_stub.hpp",
]

FILIBXX_LIBS = [
    "lib/libprim.a",
]

# Invokes ./configure, make, and make install to build filibxx. We arbitrarily
# allow make to use a number of cores equal to half the number of available
# cores, rounded up.
#
# We emit static libraries because dynamic libraries would have different names
# on OS X and on Linux, and Bazel genrules don't allow platform-dependent outs.
# https://github.com/bazelbuild/bazel/issues/281
HALF_THE_CORES = "$$[($$(getconf _NPROCESSORS_ONLN)+1)/2]"

LOG = " 2>> filibxx.log"

PRINT_ERRORS = (
    "echo \"***FILIBXX Build stderr***\"" +
    " && cat filibxx.log" +
    " && echo \"***FILIBXX Build config.log***\"" +
    " && find -L . -name config.log | xargs cat"
)

BUILD_FILIBXX_CMD = (
    "(" + CDEXEC_WITH_DIR + " `pwd`/external/filibxx autoreconf -if " + LOG +
    " && " + CDEXEC + " `pwd`/external/filibxx/configure CXXFLAGS=--std=c++11 --prefix=`pwd`/$(@D)" + LOG +
    " && " + CDEXEC + " make -j " + HALF_THE_CORES + LOG +
    " && " + CDEXEC + " make test" + LOG +
    " && " + CDEXEC + " make install" + LOG +
    ") || (" + PRINT_ERRORS + " && false)"
)

genrule(
    name = "build_with_autotools",
    srcs = glob(["**/*"]),
    outs = FILIBXX_HDRS + FILIBXX_LIBS,
    cmd = BUILD_FILIBXX_CMD,
    tools = ["@//tools/third_party/kythe/tools/cdexec:cdexec"],
    visibility = ["//visibility:private"],
)

cc_library(
    name = "filibxx",
    srcs = FILIBXX_LIBS,
    hdrs = FILIBXX_HDRS,
    includes = [
        "include",
    ],
    linkstatic = 1,
    visibility = ["//visibility:public"],
    alwayslink = 1,
)
