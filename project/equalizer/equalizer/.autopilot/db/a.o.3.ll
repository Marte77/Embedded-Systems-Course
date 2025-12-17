; ModuleID = 'C:/Users/marti/Documents/EmbeddedSystems/project/equalizer/equalizer/.autopilot/db/a.o.3.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

@iir_y_2 = internal unnamed_addr global [5 x float] zeroinitializer ; [#uses=1 type=[5 x float]*]
@iir_y_1 = internal unnamed_addr global [5 x float] zeroinitializer ; [#uses=1 type=[5 x float]*]
@iir_x_1 = internal unnamed_addr global [5 x float] zeroinitializer ; [#uses=1 type=[5 x float]*]
@iir_x_0 = internal unnamed_addr global [5 x float] zeroinitializer ; [#uses=1 type=[5 x float]*]
@iir_coeff_array = internal global [30 x float] zeroinitializer ; [#uses=6 type=[30 x float]*]
@equalizer_str = internal unnamed_addr constant [10 x i8] c"equalizer\00" ; [#uses=1 type=[10 x i8]*]
@RAM_1P_str = internal unnamed_addr constant [7 x i8] c"RAM_1P\00" ; [#uses=1 type=[7 x i8]*]
@p_str5 = internal unnamed_addr constant [1 x i8] zeroinitializer ; [#uses=7 type=[1 x i8]*]
@p_str4 = private unnamed_addr constant [12 x i8] c"filter_loop\00", align 1 ; [#uses=1 type=[12 x i8]*]
@p_str3 = private unnamed_addr constant [15 x i8] c"setCoeffs_loop\00", align 1 ; [#uses=1 type=[15 x i8]*]
@p_str2 = private unnamed_addr constant [6 x i8] c"eq_io\00", align 1 ; [#uses=5 type=[6 x i8]*]
@p_str1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=25 type=[1 x i8]*]
@p_str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=5 type=[10 x i8]*]

; [#uses=16]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=0]
define void @equalizer(float* %y, float %x, i32 %mode, [30 x float]* %coeffs) nounwind {
codeRepl:
  call void (...)* @_ssdm_op_SpecBitsMap(float* %y) nounwind, !map !23
  call void (...)* @_ssdm_op_SpecBitsMap(float %x) nounwind, !map !29
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %mode) nounwind, !map !35
  call void (...)* @_ssdm_op_SpecBitsMap([30 x float]* %coeffs) nounwind, !map !39
  call void (...)* @_ssdm_op_SpecTopModule([10 x i8]* @equalizer_str) nounwind
  %mode_read = call i32 @_ssdm_op_Read.s_axilite.i32(i32 %mode) nounwind ; [#uses=1 type=i32]
  call void @llvm.dbg.value(metadata !{i32 %mode_read}, i64 0, metadata !46), !dbg !61 ; [debug line = 3:41] [debug variable = mode]
  %x_read = call float @_ssdm_op_Read.s_axilite.float(float %x) nounwind ; [#uses=1 type=float]
  call void @llvm.dbg.value(metadata !{float %x_read}, i64 0, metadata !62), !dbg !63 ; [debug line = 3:34] [debug variable = x]
  call void @llvm.dbg.value(metadata !{float* %y}, i64 0, metadata !64), !dbg !65 ; [debug line = 3:24] [debug variable = y]
  call void @llvm.dbg.value(metadata !{float %x}, i64 0, metadata !62), !dbg !63 ; [debug line = 3:34] [debug variable = x]
  call void @llvm.dbg.value(metadata !{i32 %mode}, i64 0, metadata !46), !dbg !61 ; [debug line = 3:41] [debug variable = mode]
  call void @llvm.dbg.value(metadata !{[30 x float]* %coeffs}, i64 0, metadata !66), !dbg !70 ; [debug line = 3:54] [debug variable = coeffs]
  %empty = call i32 (...)* @_ssdm_op_SpecMemCore([30 x float]* %coeffs, [1 x i8]* @p_str5, [7 x i8]* @RAM_1P_str, [1 x i8]* @p_str5, i32 -1, [1 x i8]* @p_str5, [1 x i8]* @p_str5, [1 x i8]* @p_str5, [1 x i8]* @p_str5, [1 x i8]* @p_str5) nounwind ; [#uses=0 type=i32]
  call void (...)* @_ssdm_op_SpecInterface([30 x float]* %coeffs, [10 x i8]* @p_str, i32 0, i32 0, [1 x i8]* @p_str1, i32 0, i32 0, [6 x i8]* @p_str2, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1)
  call void (...)* @_ssdm_op_SpecInterface(i32 %mode, [10 x i8]* @p_str, i32 0, i32 0, [1 x i8]* @p_str1, i32 0, i32 0, [6 x i8]* @p_str2, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1) nounwind, !dbg !71 ; [debug line = 4:1]
  call void (...)* @_ssdm_op_SpecInterface(float %x, [10 x i8]* @p_str, i32 0, i32 0, [1 x i8]* @p_str1, i32 0, i32 0, [6 x i8]* @p_str2, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1) nounwind, !dbg !71 ; [debug line = 4:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @p_str, i32 0, i32 0, [1 x i8]* @p_str1, i32 0, i32 0, [6 x i8]* @p_str2, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1) nounwind, !dbg !71 ; [debug line = 4:1]
  call void (...)* @_ssdm_op_SpecInterface(float* %y, [10 x i8]* @p_str, i32 0, i32 0, [1 x i8]* @p_str1, i32 0, i32 0, [6 x i8]* @p_str2, [1 x i8]* @p_str1, [1 x i8]* @p_str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @p_str1, [1 x i8]* @p_str1) nounwind, !dbg !71 ; [debug line = 4:1]
  %tmp_1 = icmp eq i32 %mode_read, 1, !dbg !73    ; [#uses=1 type=i1] [debug line = 5:3]
  br i1 %tmp_1, label %.preheader4.preheader, label %.preheader.preheader, !dbg !73 ; [debug line = 5:3]

.preheader4.preheader:                            ; preds = %codeRepl
  br label %.preheader4, !dbg !74                 ; [debug line = 34:26@6:9]

.preheader.preheader:                             ; preds = %codeRepl
  br label %.preheader

.preheader4:                                      ; preds = %0, %.preheader4.preheader
  %temp_i = phi float [ %acc, %0 ], [ %x_read, %.preheader4.preheader ] ; [#uses=3 type=float]
  %i_i = phi i3 [ %i, %0 ], [ 0, %.preheader4.preheader ] ; [#uses=5 type=i3]
  %i_i_cast3 = zext i3 %i_i to i32, !dbg !74      ; [#uses=4 type=i32] [debug line = 34:26@6:9]
  %tmp = call i6 @_ssdm_op_BitConcatenate.i6.i3.i3(i3 %i_i, i3 0) ; [#uses=1 type=i6]
  %tmp_2 = call i4 @_ssdm_op_BitConcatenate.i4.i3.i1(i3 %i_i, i1 false) ; [#uses=1 type=i4]
  %p_shl1_cast = zext i4 %tmp_2 to i6, !dbg !98   ; [#uses=1 type=i6] [debug line = 36:4@6:9]
  %tmp_3 = sub i6 %tmp, %p_shl1_cast, !dbg !98    ; [#uses=5 type=i6] [debug line = 36:4@6:9]
  %tmp_3_cast = sext i6 %tmp_3 to i32, !dbg !98   ; [#uses=1 type=i32] [debug line = 36:4@6:9]
  %iir_coeff_array_addr = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_3_cast, !dbg !98 ; [#uses=1 type=float*] [debug line = 36:4@6:9]
  %tmp_4 = or i6 %tmp_3, 1, !dbg !100             ; [#uses=1 type=i6] [debug line = 37:4@6:9]
  %tmp_4_cast = zext i6 %tmp_4 to i32, !dbg !100  ; [#uses=1 type=i32] [debug line = 37:4@6:9]
  %iir_coeff_array_addr_1 = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_4_cast, !dbg !100 ; [#uses=1 type=float*] [debug line = 37:4@6:9]
  %tmp_5 = add i6 %tmp_3, 2, !dbg !101            ; [#uses=1 type=i6] [debug line = 38:4@6:9]
  %tmp_5_cast = sext i6 %tmp_5 to i32, !dbg !101  ; [#uses=1 type=i32] [debug line = 38:4@6:9]
  %iir_coeff_array_addr_2 = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_5_cast, !dbg !101 ; [#uses=1 type=float*] [debug line = 38:4@6:9]
  %tmp_6 = add i6 %tmp_3, 4, !dbg !102            ; [#uses=1 type=i6] [debug line = 39:4@6:9]
  %tmp_6_cast = sext i6 %tmp_6 to i32, !dbg !102  ; [#uses=1 type=i32] [debug line = 39:4@6:9]
  %iir_coeff_array_addr_3 = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_6_cast, !dbg !102 ; [#uses=1 type=float*] [debug line = 39:4@6:9]
  %tmp_7 = add i6 %tmp_3, 5, !dbg !103            ; [#uses=1 type=i6] [debug line = 40:4@6:9]
  %tmp_7_cast = sext i6 %tmp_7 to i32, !dbg !103  ; [#uses=1 type=i32] [debug line = 40:4@6:9]
  %iir_coeff_array_addr_4 = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_7_cast, !dbg !103 ; [#uses=1 type=float*] [debug line = 40:4@6:9]
  %exitcond_i = icmp eq i3 %i_i, -3, !dbg !74     ; [#uses=1 type=i1] [debug line = 34:26@6:9]
  %empty_2 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 5, i64 5, i64 5) nounwind ; [#uses=0 type=i32]
  %i = add i3 %i_i, 1, !dbg !104                  ; [#uses=1 type=i3] [debug line = 34:40@6:9]
  br i1 %exitcond_i, label %filter.exit, label %0, !dbg !74 ; [debug line = 34:26@6:9]

; <label>:0                                       ; preds = %.preheader4
  call void (...)* @_ssdm_op_SpecLoopName([12 x i8]* @p_str4) nounwind, !dbg !105 ; [debug line = 34:45@6:9]
  %b0 = load float* %iir_coeff_array_addr, align 8, !dbg !98 ; [#uses=1 type=float] [debug line = 36:4@6:9]
  call void @llvm.dbg.value(metadata !{float %b0}, i64 0, metadata !106) nounwind, !dbg !98 ; [debug line = 36:4@6:9] [debug variable = b0]
  %b1 = load float* %iir_coeff_array_addr_1, align 4, !dbg !100 ; [#uses=1 type=float] [debug line = 37:4@6:9]
  call void @llvm.dbg.value(metadata !{float %b1}, i64 0, metadata !107) nounwind, !dbg !100 ; [debug line = 37:4@6:9] [debug variable = b1]
  %b2 = load float* %iir_coeff_array_addr_2, align 8, !dbg !101 ; [#uses=1 type=float] [debug line = 38:4@6:9]
  call void @llvm.dbg.value(metadata !{float %b2}, i64 0, metadata !108) nounwind, !dbg !101 ; [debug line = 38:4@6:9] [debug variable = b2]
  %a1 = load float* %iir_coeff_array_addr_3, align 8, !dbg !102 ; [#uses=1 type=float] [debug line = 39:4@6:9]
  call void @llvm.dbg.value(metadata !{float %a1}, i64 0, metadata !109) nounwind, !dbg !102 ; [debug line = 39:4@6:9] [debug variable = a1]
  %a2 = load float* %iir_coeff_array_addr_4, align 4, !dbg !103 ; [#uses=1 type=float] [debug line = 40:4@6:9]
  call void @llvm.dbg.value(metadata !{float %a2}, i64 0, metadata !110) nounwind, !dbg !103 ; [debug line = 40:4@6:9] [debug variable = a2]
  %iir_x_1_addr = getelementptr [5 x float]* @iir_x_1, i32 0, i32 %i_i_cast3, !dbg !111 ; [#uses=2 type=float*] [debug line = 42:4@6:9]
  %iir_x_1_load = load float* %iir_x_1_addr, align 4, !dbg !111 ; [#uses=1 type=float] [debug line = 42:4@6:9]
  %iir_x_0_addr = getelementptr [5 x float]* @iir_x_0, i32 0, i32 %i_i_cast3, !dbg !112 ; [#uses=2 type=float*] [debug line = 43:4@6:9]
  %iir_x_0_load = load float* %iir_x_0_addr, align 4, !dbg !112 ; [#uses=2 type=float] [debug line = 43:4@6:9]
  store float %iir_x_0_load, float* %iir_x_1_addr, align 4, !dbg !112 ; [debug line = 43:4@6:9]
  store float %temp_i, float* %iir_x_0_addr, align 4, !dbg !113 ; [debug line = 44:4@6:9]
  %tmp_i = fmul float %b0, %temp_i, !dbg !114     ; [#uses=1 type=float] [debug line = 46:4@6:9]
  %tmp_3_i = fmul float %b1, %iir_x_0_load, !dbg !114 ; [#uses=1 type=float] [debug line = 46:4@6:9]
  %tmp_4_i = fadd float %tmp_i, %tmp_3_i, !dbg !114 ; [#uses=1 type=float] [debug line = 46:4@6:9]
  %tmp_5_i = fmul float %b2, %iir_x_1_load, !dbg !114 ; [#uses=1 type=float] [debug line = 46:4@6:9]
  %tmp_6_i = fadd float %tmp_4_i, %tmp_5_i, !dbg !114 ; [#uses=1 type=float] [debug line = 46:4@6:9]
  %iir_y_1_addr = getelementptr [5 x float]* @iir_y_1, i32 0, i32 %i_i_cast3, !dbg !114 ; [#uses=2 type=float*] [debug line = 46:4@6:9]
  %iir_y_1_load = load float* %iir_y_1_addr, align 4, !dbg !114 ; [#uses=2 type=float] [debug line = 46:4@6:9]
  %tmp_7_i = fmul float %a1, %iir_y_1_load, !dbg !114 ; [#uses=1 type=float] [debug line = 46:4@6:9]
  %tmp_8_i = fsub float %tmp_6_i, %tmp_7_i, !dbg !114 ; [#uses=1 type=float] [debug line = 46:4@6:9]
  %iir_y_2_addr = getelementptr [5 x float]* @iir_y_2, i32 0, i32 %i_i_cast3, !dbg !114 ; [#uses=2 type=float*] [debug line = 46:4@6:9]
  %iir_y_2_load = load float* %iir_y_2_addr, align 4, !dbg !114 ; [#uses=1 type=float] [debug line = 46:4@6:9]
  %tmp_9_i = fmul float %a2, %iir_y_2_load, !dbg !114 ; [#uses=1 type=float] [debug line = 46:4@6:9]
  %acc = fsub float %tmp_8_i, %tmp_9_i, !dbg !114 ; [#uses=2 type=float] [debug line = 46:4@6:9]
  call void @llvm.dbg.value(metadata !{float %acc}, i64 0, metadata !115) nounwind, !dbg !114 ; [debug line = 46:4@6:9] [debug variable = acc]
  store float %iir_y_1_load, float* %iir_y_2_addr, align 4, !dbg !116 ; [debug line = 50:4@6:9]
  store float %acc, float* %iir_y_1_addr, align 4, !dbg !117 ; [debug line = 51:4@6:9]
  call void @llvm.dbg.value(metadata !{float %acc}, i64 0, metadata !118) nounwind, !dbg !119 ; [debug line = 52:4@6:9] [debug variable = temp]
  call void @llvm.dbg.value(metadata !{i3 %i}, i64 0, metadata !120) nounwind, !dbg !104 ; [debug line = 34:40@6:9] [debug variable = i]
  br label %.preheader4, !dbg !104                ; [debug line = 34:40@6:9]

filter.exit:                                      ; preds = %.preheader4
  call void @_ssdm_op_Write.s_axilite.floatP(float* %y, float %temp_i) nounwind, !dbg !97 ; [debug line = 6:9]
  br label %setCoeffs.exit, !dbg !97              ; [debug line = 6:9]

.preheader.loopexit:                              ; preds = %.preheader.i
  br label %.preheader

.preheader:                                       ; preds = %.preheader.loopexit, %.preheader.preheader
  %i_i1 = phi i3 [ %i_1, %.preheader.loopexit ], [ 0, %.preheader.preheader ] ; [#uses=4 type=i3]
  %tmp_8 = call i6 @_ssdm_op_BitConcatenate.i6.i3.i3(i3 %i_i1, i3 0) ; [#uses=1 type=i6]
  %tmp_9 = call i4 @_ssdm_op_BitConcatenate.i4.i3.i1(i3 %i_i1, i1 false) ; [#uses=1 type=i4]
  %p_shl3_cast = zext i4 %tmp_9 to i6, !dbg !121  ; [#uses=1 type=i6] [debug line = 27:5@8:4]
  %tmp_s = sub i6 %tmp_8, %p_shl3_cast, !dbg !121 ; [#uses=1 type=i6] [debug line = 27:5@8:4]
  %exitcond1_i = icmp eq i3 %i_i1, -3, !dbg !130  ; [#uses=1 type=i1] [debug line = 25:14@8:4]
  %empty_3 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 5, i64 5, i64 5) nounwind ; [#uses=0 type=i32]
  %i_1 = add i3 %i_i1, 1, !dbg !131               ; [#uses=1 type=i3] [debug line = 25:28@8:4]
  call void @llvm.dbg.value(metadata !{i3 %i_1}, i64 0, metadata !132) nounwind, !dbg !131 ; [debug line = 25:28@8:4] [debug variable = i]
  br i1 %exitcond1_i, label %setCoeffs.exit.loopexit, label %.preheader.i.preheader, !dbg !130 ; [debug line = 25:14@8:4]

.preheader.i.preheader:                           ; preds = %.preheader
  br label %.preheader.i, !dbg !121               ; [debug line = 27:5@8:4]

.preheader.i:                                     ; preds = %1, %.preheader.i.preheader
  %j_i = phi i3 [ %j, %1 ], [ 0, %.preheader.i.preheader ] ; [#uses=3 type=i3]
  %j_i_cast1_cast = zext i3 %j_i to i6, !dbg !121 ; [#uses=1 type=i6] [debug line = 27:5@8:4]
  %tmp_10 = add i6 %tmp_s, %j_i_cast1_cast, !dbg !121 ; [#uses=1 type=i6] [debug line = 27:5@8:4]
  %tmp_11_cast = sext i6 %tmp_10 to i32, !dbg !121 ; [#uses=2 type=i32] [debug line = 27:5@8:4]
  %coeffs_addr = getelementptr [30 x float]* %coeffs, i32 0, i32 %tmp_11_cast, !dbg !121 ; [#uses=1 type=float*] [debug line = 27:5@8:4]
  %iir_coeff_array_addr_5 = getelementptr [30 x float]* @iir_coeff_array, i32 0, i32 %tmp_11_cast, !dbg !121 ; [#uses=1 type=float*] [debug line = 27:5@8:4]
  %exitcond_i2 = icmp eq i3 %j_i, -2, !dbg !133   ; [#uses=1 type=i1] [debug line = 26:31@8:4]
  %empty_4 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 6, i64 6, i64 6) nounwind ; [#uses=0 type=i32]
  %j = add i3 %j_i, 1, !dbg !134                  ; [#uses=1 type=i3] [debug line = 26:40@8:4]
  br i1 %exitcond_i2, label %.preheader.loopexit, label %1, !dbg !133 ; [debug line = 26:31@8:4]

; <label>:1                                       ; preds = %.preheader.i
  call void (...)* @_ssdm_op_SpecLoopName([15 x i8]* @p_str3) nounwind, !dbg !135 ; [debug line = 26:46@8:4]
  %coeffs_load = load float* %coeffs_addr, align 4, !dbg !121 ; [#uses=1 type=float] [debug line = 27:5@8:4]
  store float %coeffs_load, float* %iir_coeff_array_addr_5, align 4, !dbg !121 ; [debug line = 27:5@8:4]
  call void @llvm.dbg.value(metadata !{i3 %j}, i64 0, metadata !136) nounwind, !dbg !134 ; [debug line = 26:40@8:4] [debug variable = j]
  br label %.preheader.i, !dbg !134               ; [debug line = 26:40@8:4]

setCoeffs.exit.loopexit:                          ; preds = %.preheader
  br label %setCoeffs.exit

setCoeffs.exit:                                   ; preds = %setCoeffs.exit.loopexit, %filter.exit
  ret void, !dbg !137                             ; [debug line = 10:1]
}

; [#uses=1]
define weak void @_ssdm_op_Write.s_axilite.floatP(float*, float) {
entry:
  store float %1, float* %0
  ret void
}

; [#uses=1]
define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

; [#uses=1]
define weak i32 @_ssdm_op_SpecMemCore(...) {
entry:
  ret i32 0
}

; [#uses=3]
define weak i32 @_ssdm_op_SpecLoopTripCount(...) {
entry:
  ret i32 0
}

; [#uses=2]
define weak void @_ssdm_op_SpecLoopName(...) nounwind {
entry:
  ret void
}

; [#uses=5]
define weak void @_ssdm_op_SpecInterface(...) nounwind {
entry:
  ret void
}

; [#uses=4]
define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

; [#uses=1]
define weak i32 @_ssdm_op_Read.s_axilite.i32(i32) {
entry:
  ret i32 %0
}

; [#uses=1]
define weak float @_ssdm_op_Read.s_axilite.float(float) {
entry:
  ret float %0
}

; [#uses=2]
define weak i6 @_ssdm_op_BitConcatenate.i6.i3.i3(i3, i3) nounwind readnone {
entry:
  %empty = zext i3 %0 to i6                       ; [#uses=1 type=i6]
  %empty_5 = zext i3 %1 to i6                     ; [#uses=1 type=i6]
  %empty_6 = shl i6 %empty, 3                     ; [#uses=1 type=i6]
  %empty_7 = or i6 %empty_6, %empty_5             ; [#uses=1 type=i6]
  ret i6 %empty_7
}

; [#uses=2]
define weak i4 @_ssdm_op_BitConcatenate.i4.i3.i1(i3, i1) nounwind readnone {
entry:
  %empty = zext i3 %0 to i4                       ; [#uses=1 type=i4]
  %empty_8 = zext i1 %1 to i4                     ; [#uses=1 type=i4]
  %empty_9 = shl i4 %empty, 1                     ; [#uses=1 type=i4]
  %empty_10 = or i4 %empty_9, %empty_8            ; [#uses=1 type=i4]
  ret i4 %empty_10
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
!46 = metadata !{i32 786689, metadata !47, metadata !"mode", metadata !48, i32 50331651, metadata !54, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!47 = metadata !{i32 786478, i32 0, metadata !48, metadata !"equalizer", metadata !"equalizer", metadata !"_Z9equalizerPffiPA6_f", metadata !48, i32 3, metadata !49, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, null, metadata !59, i32 3} ; [ DW_TAG_subprogram ]
!48 = metadata !{i32 786473, metadata !"equalizer/iir.cpp", metadata !"C:\5CUsers\5Cmarti\5CDocuments\5CEmbeddedSystems\5Cproject", null} ; [ DW_TAG_file_type ]
!49 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !50, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!50 = metadata !{null, metadata !51, metadata !52, metadata !54, metadata !55}
!51 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !52} ; [ DW_TAG_pointer_type ]
!52 = metadata !{i32 786454, null, metadata !"data_t", metadata !48, i32 2, i64 0, i64 0, i64 0, i32 0, metadata !53} ; [ DW_TAG_typedef ]
!53 = metadata !{i32 786468, null, metadata !"float", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 4} ; [ DW_TAG_base_type ]
!54 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!55 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !56} ; [ DW_TAG_pointer_type ]
!56 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 192, i64 32, i32 0, i32 0, metadata !52, metadata !57, i32 0, i32 0} ; [ DW_TAG_array_type ]
!57 = metadata !{metadata !58}
!58 = metadata !{i32 786465, i64 0, i64 5}        ; [ DW_TAG_subrange_type ]
!59 = metadata !{metadata !60}
!60 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!61 = metadata !{i32 3, i32 41, metadata !47, null}
!62 = metadata !{i32 786689, metadata !47, metadata !"x", metadata !48, i32 33554435, metadata !52, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!63 = metadata !{i32 3, i32 34, metadata !47, null}
!64 = metadata !{i32 786689, metadata !47, metadata !"y", metadata !48, i32 16777219, metadata !51, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!65 = metadata !{i32 3, i32 24, metadata !47, null}
!66 = metadata !{i32 786689, metadata !47, metadata !"coeffs", null, i32 3, metadata !67, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!67 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 960, i64 32, i32 0, i32 0, metadata !52, metadata !68, i32 0, i32 0} ; [ DW_TAG_array_type ]
!68 = metadata !{metadata !69, metadata !58}
!69 = metadata !{i32 786465, i64 0, i64 4}        ; [ DW_TAG_subrange_type ]
!70 = metadata !{i32 3, i32 54, metadata !47, null}
!71 = metadata !{i32 4, i32 1, metadata !72, null}
!72 = metadata !{i32 786443, metadata !47, i32 3, i32 74, metadata !48, i32 0} ; [ DW_TAG_lexical_block ]
!73 = metadata !{i32 5, i32 3, metadata !72, null}
!74 = metadata !{i32 34, i32 26, metadata !75, metadata !97}
!75 = metadata !{i32 786443, metadata !76, i32 34, i32 15, metadata !78, i32 8} ; [ DW_TAG_lexical_block ]
!76 = metadata !{i32 786443, metadata !77, i32 31, i32 30, metadata !78, i32 7} ; [ DW_TAG_lexical_block ]
!77 = metadata !{i32 786478, i32 0, null, metadata !"filter", metadata !"filter", metadata !"_ZN9IIRFilter6filterEf", metadata !78, i32 31, metadata !79, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, metadata !96, metadata !59, i32 31} ; [ DW_TAG_subprogram ]
!78 = metadata !{i32 786473, metadata !"equalizer/iir.h", metadata !"C:\5CUsers\5Cmarti\5CDocuments\5CEmbeddedSystems\5Cproject", null} ; [ DW_TAG_file_type ]
!79 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !80, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!80 = metadata !{metadata !52, metadata !81, metadata !52}
!81 = metadata !{i32 786447, i32 0, metadata !"", i32 0, i32 0, i64 32, i64 32, i64 0, i32 64, metadata !82} ; [ DW_TAG_pointer_type ]
!82 = metadata !{i32 786434, null, metadata !"IIRFilter", metadata !78, i32 8, i64 1920, i64 32, i32 0, i32 0, null, metadata !83, i32 0, null, null} ; [ DW_TAG_class_type ]
!83 = metadata !{metadata !84, metadata !88, metadata !89, metadata !90, metadata !93, metadata !96}
!84 = metadata !{i32 786445, metadata !82, metadata !"x", metadata !78, i32 10, i64 480, i64 32, i64 0, i32 0, metadata !85} ; [ DW_TAG_member ]
!85 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 480, i64 32, i32 0, i32 0, metadata !52, metadata !86, i32 0, i32 0} ; [ DW_TAG_array_type ]
!86 = metadata !{metadata !69, metadata !87}
!87 = metadata !{i32 786465, i64 0, i64 2}        ; [ DW_TAG_subrange_type ]
!88 = metadata !{i32 786445, metadata !82, metadata !"y", metadata !78, i32 11, i64 480, i64 32, i64 480, i32 0, metadata !85} ; [ DW_TAG_member ]
!89 = metadata !{i32 786445, metadata !82, metadata !"coeff_array", metadata !78, i32 12, i64 960, i64 32, i64 960, i32 0, metadata !67} ; [ DW_TAG_member ]
!90 = metadata !{i32 786478, i32 0, metadata !82, metadata !"IIRFilter", metadata !"IIRFilter", metadata !"", metadata !78, i32 13, metadata !91, i1 false, i1 false, i32 0, i32 0, null, i32 256, i1 false, null, null, i32 0, metadata !59, i32 13} ; [ DW_TAG_subprogram ]
!91 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !92, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!92 = metadata !{null, metadata !81}
!93 = metadata !{i32 786478, i32 0, metadata !82, metadata !"setCoeffs", metadata !"setCoeffs", metadata !"_ZN9IIRFilter9setCoeffsEPA6_f", metadata !78, i32 24, metadata !94, i1 false, i1 false, i32 0, i32 0, null, i32 256, i1 false, null, null, i32 0, metadata !59, i32 24} ; [ DW_TAG_subprogram ]
!94 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !95, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!95 = metadata !{null, metadata !81, metadata !55}
!96 = metadata !{i32 786478, i32 0, metadata !82, metadata !"filter", metadata !"filter", metadata !"_ZN9IIRFilter6filterEf", metadata !78, i32 31, metadata !79, i1 false, i1 false, i32 0, i32 0, null, i32 256, i1 false, null, null, i32 0, metadata !59, i32 31} ; [ DW_TAG_subprogram ]
!97 = metadata !{i32 6, i32 9, metadata !72, null}
!98 = metadata !{i32 36, i32 4, metadata !99, metadata !97}
!99 = metadata !{i32 786443, metadata !75, i32 34, i32 44, metadata !78, i32 9} ; [ DW_TAG_lexical_block ]
!100 = metadata !{i32 37, i32 4, metadata !99, metadata !97}
!101 = metadata !{i32 38, i32 4, metadata !99, metadata !97}
!102 = metadata !{i32 39, i32 4, metadata !99, metadata !97}
!103 = metadata !{i32 40, i32 4, metadata !99, metadata !97}
!104 = metadata !{i32 34, i32 40, metadata !75, metadata !97}
!105 = metadata !{i32 34, i32 45, metadata !99, metadata !97}
!106 = metadata !{i32 786688, metadata !76, metadata !"b0", metadata !78, i32 32, metadata !52, i32 0, metadata !97} ; [ DW_TAG_auto_variable ]
!107 = metadata !{i32 786688, metadata !76, metadata !"b1", metadata !78, i32 32, metadata !52, i32 0, metadata !97} ; [ DW_TAG_auto_variable ]
!108 = metadata !{i32 786688, metadata !76, metadata !"b2", metadata !78, i32 32, metadata !52, i32 0, metadata !97} ; [ DW_TAG_auto_variable ]
!109 = metadata !{i32 786688, metadata !76, metadata !"a1", metadata !78, i32 32, metadata !52, i32 0, metadata !97} ; [ DW_TAG_auto_variable ]
!110 = metadata !{i32 786688, metadata !76, metadata !"a2", metadata !78, i32 32, metadata !52, i32 0, metadata !97} ; [ DW_TAG_auto_variable ]
!111 = metadata !{i32 42, i32 4, metadata !99, metadata !97}
!112 = metadata !{i32 43, i32 4, metadata !99, metadata !97}
!113 = metadata !{i32 44, i32 4, metadata !99, metadata !97}
!114 = metadata !{i32 46, i32 4, metadata !99, metadata !97}
!115 = metadata !{i32 786688, metadata !76, metadata !"acc", metadata !78, i32 32, metadata !52, i32 0, metadata !97} ; [ DW_TAG_auto_variable ]
!116 = metadata !{i32 50, i32 4, metadata !99, metadata !97}
!117 = metadata !{i32 51, i32 4, metadata !99, metadata !97}
!118 = metadata !{i32 786688, metadata !76, metadata !"temp", metadata !78, i32 32, metadata !52, i32 0, metadata !97} ; [ DW_TAG_auto_variable ]
!119 = metadata !{i32 52, i32 4, metadata !99, metadata !97}
!120 = metadata !{i32 786688, metadata !75, metadata !"i", metadata !78, i32 34, metadata !54, i32 0, metadata !97} ; [ DW_TAG_auto_variable ]
!121 = metadata !{i32 27, i32 5, metadata !122, metadata !128}
!122 = metadata !{i32 786443, metadata !123, i32 26, i32 45, metadata !78, i32 6} ; [ DW_TAG_lexical_block ]
!123 = metadata !{i32 786443, metadata !124, i32 26, i32 19, metadata !78, i32 5} ; [ DW_TAG_lexical_block ]
!124 = metadata !{i32 786443, metadata !125, i32 25, i32 33, metadata !78, i32 4} ; [ DW_TAG_lexical_block ]
!125 = metadata !{i32 786443, metadata !126, i32 25, i32 3, metadata !78, i32 3} ; [ DW_TAG_lexical_block ]
!126 = metadata !{i32 786443, metadata !127, i32 24, i32 43, metadata !78, i32 2} ; [ DW_TAG_lexical_block ]
!127 = metadata !{i32 786478, i32 0, null, metadata !"setCoeffs", metadata !"setCoeffs", metadata !"_ZN9IIRFilter9setCoeffsEPA6_f", metadata !78, i32 24, metadata !94, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, metadata !93, metadata !59, i32 24} ; [ DW_TAG_subprogram ]
!128 = metadata !{i32 8, i32 4, metadata !129, null}
!129 = metadata !{i32 786443, metadata !72, i32 7, i32 8, metadata !48, i32 1} ; [ DW_TAG_lexical_block ]
!130 = metadata !{i32 25, i32 14, metadata !125, metadata !128}
!131 = metadata !{i32 25, i32 28, metadata !125, metadata !128}
!132 = metadata !{i32 786688, metadata !125, metadata !"i", metadata !78, i32 25, metadata !54, i32 0, metadata !128} ; [ DW_TAG_auto_variable ]
!133 = metadata !{i32 26, i32 31, metadata !123, metadata !128}
!134 = metadata !{i32 26, i32 40, metadata !123, metadata !128}
!135 = metadata !{i32 26, i32 46, metadata !122, metadata !128}
!136 = metadata !{i32 786688, metadata !123, metadata !"j", metadata !78, i32 26, metadata !54, i32 0, metadata !128} ; [ DW_TAG_auto_variable ]
!137 = metadata !{i32 10, i32 1, metadata !72, null}
