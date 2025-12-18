; ModuleID = 'C:/Users/marti/Documents/GitHub/Embedded-Systems-Course/project/equalizer/equalizer/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

@iir_y_2 = internal unnamed_addr global [5 x float] zeroinitializer
@iir_y_1 = internal unnamed_addr global [5 x float] zeroinitializer
@iir_x_1 = internal unnamed_addr global [5 x float] zeroinitializer
@iir_x_0 = internal unnamed_addr global [5 x float] zeroinitializer
@iir_coeff_array = internal global [30 x float] zeroinitializer
@equalizer_str = internal unnamed_addr constant [10 x i8] c"equalizer\00"
@RAM_1P_str = internal unnamed_addr constant [7 x i8] c"RAM_1P\00"
@p_str5 = internal unnamed_addr constant [1 x i8] zeroinitializer
@p_str4 = private unnamed_addr constant [12 x i8] c"filter_loop\00", align 1
@p_str3 = private unnamed_addr constant [15 x i8] c"setCoeffs_loop\00", align 1
@p_str2 = private unnamed_addr constant [6 x i8] c"eq_io\00", align 1
@p_str1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@p_str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1

declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

define void @equalizer(float* %y, float %x, i32 %mode, [30 x float]* %coeffs) nounwind {
codeRepl:
  call void (...)* @_ssdm_op_SpecBitsMap(float* %y) nounwind, !map !23
  call void (...)* @_ssdm_op_SpecBitsMap(float %x) nounwind, !map !29
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %mode) nounwind, !map !35
  call void (...)* @_ssdm_op_SpecBitsMap([30 x float]* %coeffs) nounwind, !map !39
  call void (...)* @_ssdm_op_SpecTopModule([10 x i8]* @equalizer_str) nounwind
  %mode_read = call i32 @_ssdm_op_Read.s_axilite.i32(i32 %mode) nounwind
  %x_read = call float @_ssdm_op_Read.s_axilite.float(float %x) nounwind
  %empty = call i32 (...)* @_ssdm_op_SpecMemCore([30 x float]* %coeffs, [1 x i8]* @p_str5, [7 x i8]* @RAM_1P_str, [1 x i8]* @p_str5, i32 -1, [1 x i8]* @p_str5, [1 x i8]* @p_str5, [1 x i8]* @p_str5, [1 x i8]* @p_str5, [1 x i8]* @p_str5) nounwind
  call void (...)* @_ssdm_op_SpecInterface([30 x float]* %coeffs, [10 x i8]* @p_str, i32 0, i32 0, [1 x i8]* @p_str1, i32 0, i32 0, [6 x i8]* @p_str2, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1)
  call void (...)* @_ssdm_op_SpecInterface(i32 %mode, [10 x i8]* @p_str, i32 0, i32 0, [1 x i8]* @p_str1, i32 0, i32 0, [6 x i8]* @p_str2, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1) nounwind
  call void (...)* @_ssdm_op_SpecInterface(float %x, [10 x i8]* @p_str, i32 0, i32 0, [1 x i8]* @p_str1, i32 0, i32 0, [6 x i8]* @p_str2, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @p_str, i32 0, i32 0, [1 x i8]* @p_str1, i32 0, i32 0, [6 x i8]* @p_str2, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1) nounwind
  call void (...)* @_ssdm_op_SpecInterface(float* %y, [10 x i8]* @p_str, i32 0, i32 0, [1 x i8]* @p_str1, i32 0, i32 0, [6 x i8]* @p_str2, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1) nounwind
  %tmp_1 = icmp eq i32 %mode_read, 1
  br i1 %tmp_1, label %.preheader4.preheader, label %.preheader.preheader

.preheader4.preheader:                            ; preds = %codeRepl
  br label %.preheader4

.preheader.preheader:                             ; preds = %codeRepl
  br label %.preheader

.preheader4:                                      ; preds = %.preheader4.preheader, %0
  %temp_i = phi float [ %acc, %0 ], [ %x_read, %.preheader4.preheader ]
  %i_i = phi i3 [ %i, %0 ], [ 0, %.preheader4.preheader ]
  %i_i_cast3 = zext i3 %i_i to i32
  %tmp = call i6 @_ssdm_op_BitConcatenate.i6.i3.i3(i3 %i_i, i3 0)
  %tmp_2 = call i4 @_ssdm_op_BitConcatenate.i4.i3.i1(i3 %i_i, i1 false)
  %p_shl1_cast = zext i4 %tmp_2 to i6
  %tmp_3 = sub i6 %tmp, %p_shl1_cast
  %tmp_3_cast = sext i6 %tmp_3 to i32
  %iir_coeff_array_addr = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_3_cast
  %tmp_4 = or i6 %tmp_3, 1
  %tmp_4_cast = zext i6 %tmp_4 to i32
  %iir_coeff_array_addr_1 = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_4_cast
  %tmp_5 = add i6 %tmp_3, 2
  %tmp_5_cast = sext i6 %tmp_5 to i32
  %iir_coeff_array_addr_2 = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_5_cast
  %tmp_6 = add i6 %tmp_3, 3
  %tmp_6_cast = sext i6 %tmp_6 to i32
  %iir_coeff_array_addr_3 = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_6_cast
  %tmp_7 = add i6 %tmp_3, 4
  %tmp_7_cast = sext i6 %tmp_7 to i32
  %iir_coeff_array_addr_4 = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_7_cast
  %tmp_8 = add i6 %tmp_3, 5
  %tmp_8_cast = sext i6 %tmp_8 to i32
  %iir_coeff_array_addr_5 = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_8_cast
  %exitcond_i = icmp eq i3 %i_i, -3
  %empty_2 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 5, i64 5, i64 5) nounwind
  %i = add i3 %i_i, 1
  br i1 %exitcond_i, label %filter.exit, label %0

; <label>:0                                       ; preds = %.preheader4
  call void (...)* @_ssdm_op_SpecLoopName([12 x i8]* @p_str4) nounwind
  %b0 = load float* %iir_coeff_array_addr, align 8
  %b1 = load float* %iir_coeff_array_addr_1, align 4
  %b2 = load float* %iir_coeff_array_addr_2, align 8
  %a0 = load float* %iir_coeff_array_addr_3, align 4
  %a1 = load float* %iir_coeff_array_addr_4, align 8
  %a2 = load float* %iir_coeff_array_addr_5, align 4
  %iir_x_1_addr = getelementptr [5 x float]* @iir_x_1, i32 0, i32 %i_i_cast3
  %iir_x_1_load = load float* %iir_x_1_addr, align 4
  %iir_x_0_addr = getelementptr [5 x float]* @iir_x_0, i32 0, i32 %i_i_cast3
  %iir_x_0_load = load float* %iir_x_0_addr, align 4
  store float %iir_x_0_load, float* %iir_x_1_addr, align 4
  store float %temp_i, float* %iir_x_0_addr, align 4
  %tmp_i = fmul float %b0, %temp_i
  %tmp_3_i = fdiv float %tmp_i, %a0
  %tmp_4_i = fmul float %b1, %iir_x_0_load
  %tmp_5_i = fdiv float %tmp_4_i, %a0
  %tmp_6_i = fadd float %tmp_3_i, %tmp_5_i
  %tmp_7_i = fmul float %b2, %iir_x_1_load
  %tmp_8_i = fdiv float %tmp_7_i, %a0
  %tmp_9_i = fadd float %tmp_6_i, %tmp_8_i
  %iir_y_1_addr = getelementptr [5 x float]* @iir_y_1, i32 0, i32 %i_i_cast3
  %iir_y_1_load = load float* %iir_y_1_addr, align 4
  %tmp_i_3 = fmul float %a1, %iir_y_1_load
  %tmp_1_i = fdiv float %tmp_i_3, %a0
  %tmp_2_i = fsub float %tmp_9_i, %tmp_1_i
  %iir_y_2_addr = getelementptr [5 x float]* @iir_y_2, i32 0, i32 %i_i_cast3
  %iir_y_2_load = load float* %iir_y_2_addr, align 4
  %tmp_10_i = fmul float %a2, %iir_y_2_load
  %tmp_11_i = fdiv float %tmp_10_i, %a0
  %acc = fsub float %tmp_2_i, %tmp_11_i
  store float %iir_y_1_load, float* %iir_y_2_addr, align 4
  store float %acc, float* %iir_y_1_addr, align 4
  br label %.preheader4

filter.exit:                                      ; preds = %.preheader4
  call void @_ssdm_op_Write.s_axilite.floatP(float* %y, float %temp_i) nounwind
  br label %setCoeffs.exit

.preheader.loopexit:                              ; preds = %.preheader.i
  br label %.preheader

.preheader:                                       ; preds = %.preheader.preheader, %.preheader.loopexit
  %i_i1 = phi i3 [ %i_1, %.preheader.loopexit ], [ 0, %.preheader.preheader ]
  %tmp_9 = call i6 @_ssdm_op_BitConcatenate.i6.i3.i3(i3 %i_i1, i3 0)
  %tmp_s = call i4 @_ssdm_op_BitConcatenate.i4.i3.i1(i3 %i_i1, i1 false)
  %p_shl3_cast = zext i4 %tmp_s to i6
  %tmp_10 = sub i6 %tmp_9, %p_shl3_cast
  %exitcond1_i = icmp eq i3 %i_i1, -3
  %empty_4 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 5, i64 5, i64 5) nounwind
  %i_1 = add i3 %i_i1, 1
  br i1 %exitcond1_i, label %setCoeffs.exit.loopexit, label %.preheader.i.preheader

.preheader.i.preheader:                           ; preds = %.preheader
  br label %.preheader.i

.preheader.i:                                     ; preds = %.preheader.i.preheader, %1
  %j_i = phi i3 [ %j, %1 ], [ 0, %.preheader.i.preheader ]
  %j_i_cast1_cast = zext i3 %j_i to i6
  %tmp_11 = add i6 %tmp_10, %j_i_cast1_cast
  %tmp_12_cast = sext i6 %tmp_11 to i32
  %coeffs_addr = getelementptr [30 x float]* %coeffs, i32 0, i32 %tmp_12_cast
  %iir_coeff_array_addr_6 = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_12_cast
  %exitcond_i2 = icmp eq i3 %j_i, -2
  %empty_5 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 6, i64 6, i64 6) nounwind
  %j = add i3 %j_i, 1
  br i1 %exitcond_i2, label %.preheader.loopexit, label %1

; <label>:1                                       ; preds = %.preheader.i
  call void (...)* @_ssdm_op_SpecLoopName([15 x i8]* @p_str3) nounwind
  %coeffs_load = load float* %coeffs_addr, align 4
  store float %coeffs_load, float* %iir_coeff_array_addr_6, align 4
  br label %.preheader.i

setCoeffs.exit.loopexit:                          ; preds = %.preheader
  br label %setCoeffs.exit

setCoeffs.exit:                                   ; preds = %setCoeffs.exit.loopexit, %filter.exit
  ret void
}

define weak void @_ssdm_op_Write.s_axilite.floatP(float*, float) {
entry:
  store float %1, float* %0
  ret void
}

define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

define weak i32 @_ssdm_op_SpecMemCore(...) {
entry:
  ret i32 0
}

define weak i32 @_ssdm_op_SpecLoopTripCount(...) {
entry:
  ret i32 0
}

define weak void @_ssdm_op_SpecLoopName(...) nounwind {
entry:
  ret void
}

define weak void @_ssdm_op_SpecInterface(...) nounwind {
entry:
  ret void
}

define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

define weak i32 @_ssdm_op_Read.s_axilite.i32(i32) {
entry:
  ret i32 %0
}

define weak float @_ssdm_op_Read.s_axilite.float(float) {
entry:
  ret float %0
}

define weak i6 @_ssdm_op_BitConcatenate.i6.i3.i3(i3, i3) nounwind readnone {
entry:
  %empty = zext i3 %0 to i6
  %empty_6 = zext i3 %1 to i6
  %empty_7 = shl i6 %empty, 3
  %empty_8 = or i6 %empty_7, %empty_6
  ret i6 %empty_8
}

define weak i4 @_ssdm_op_BitConcatenate.i4.i3.i1(i3, i1) nounwind readnone {
entry:
  %empty = zext i3 %0 to i4
  %empty_9 = zext i1 %1 to i4
  %empty_10 = shl i4 %empty, 1
  %empty_11 = or i4 %empty_10, %empty_9
  ret i4 %empty_11
}

!opencl.kernels = !{!0, !7, !13, !17, !17}
!hls.encrypted.func = !{}
!llvm.map.gv = !{}

!0 = metadata !{null, metadata !1, metadata !2, metadata !3, metadata !4, metadata !5, metadata !6}
!1 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 0, i32 0, i32 1}
!2 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none", metadata !"none"}
!3 = metadata !{metadata !"kernel_arg_type", metadata !"data_t*", metadata !"data_t", metadata !"int", metadata !"data_t [6]*"}
!4 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !"", metadata !""}
!5 = metadata !{metadata !"kernel_arg_name", metadata !"y", metadata !"x", metadata !"mode", metadata !"coeffs"}
!6 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!7 = metadata !{null, metadata !8, metadata !9, metadata !10, metadata !11, metadata !12, metadata !6}
!8 = metadata !{metadata !"kernel_arg_addr_space", i32 1}
!9 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none"}
!10 = metadata !{metadata !"kernel_arg_type", metadata !"data_t [6]*"}
!11 = metadata !{metadata !"kernel_arg_type_qual", metadata !""}
!12 = metadata !{metadata !"kernel_arg_name", metadata !"coefs"}
!13 = metadata !{null, metadata !14, metadata !9, metadata !15, metadata !11, metadata !16, metadata !6}
!14 = metadata !{metadata !"kernel_arg_addr_space", i32 0}
!15 = metadata !{metadata !"kernel_arg_type", metadata !"data_t"}
!16 = metadata !{metadata !"kernel_arg_name", metadata !"input"}
!17 = metadata !{null, metadata !18, metadata !19, metadata !20, metadata !21, metadata !22, metadata !6}
!18 = metadata !{metadata !"kernel_arg_addr_space"}
!19 = metadata !{metadata !"kernel_arg_access_qual"}
!20 = metadata !{metadata !"kernel_arg_type"}
!21 = metadata !{metadata !"kernel_arg_type_qual"}
!22 = metadata !{metadata !"kernel_arg_name"}
!23 = metadata !{metadata !24}
!24 = metadata !{i32 0, i32 31, metadata !25}
!25 = metadata !{metadata !26}
!26 = metadata !{metadata !"y", metadata !27, metadata !"float", i32 0, i32 31}
!27 = metadata !{metadata !28}
!28 = metadata !{i32 0, i32 0, i32 1}
!29 = metadata !{metadata !30}
!30 = metadata !{i32 0, i32 31, metadata !31}
!31 = metadata !{metadata !32}
!32 = metadata !{metadata !"x", metadata !33, metadata !"float", i32 0, i32 31}
!33 = metadata !{metadata !34}
!34 = metadata !{i32 0, i32 0, i32 0}
!35 = metadata !{metadata !36}
!36 = metadata !{i32 0, i32 31, metadata !37}
!37 = metadata !{metadata !38}
!38 = metadata !{metadata !"mode", metadata !33, metadata !"int", i32 0, i32 31}
!39 = metadata !{metadata !40}
!40 = metadata !{i32 0, i32 31, metadata !41}
!41 = metadata !{metadata !42}
!42 = metadata !{metadata !"coeffs", metadata !43, metadata !"float", i32 0, i32 31}
!43 = metadata !{metadata !44, metadata !45}
!44 = metadata !{i32 0, i32 4, i32 1}
!45 = metadata !{i32 0, i32 5, i32 1}
