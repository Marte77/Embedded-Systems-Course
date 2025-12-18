; ModuleID = 'C:/Users/marti/Documents/GitHub/Embedded-Systems-Course/project/equalizer/equalizer/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

@iir.y.2 = internal unnamed_addr global [5 x float] zeroinitializer ; [#uses=1 type=[5 x float]*]
@iir.y.1 = internal unnamed_addr global [5 x float] zeroinitializer ; [#uses=1 type=[5 x float]*]
@iir.x.1 = internal unnamed_addr global [5 x float] zeroinitializer ; [#uses=1 type=[5 x float]*]
@iir.x.0 = internal unnamed_addr global [5 x float] zeroinitializer ; [#uses=1 type=[5 x float]*]
@iir.coeff_array = internal unnamed_addr global [5 x [6 x float]] zeroinitializer ; [#uses=7 type=[5 x [6 x float]]*]
@equalizer.str = internal unnamed_addr constant [10 x i8] c"equalizer\00" ; [#uses=1 type=[10 x i8]*]
@.str4 = private unnamed_addr constant [12 x i8] c"filter_loop\00", align 1 ; [#uses=1 type=[12 x i8]*]
@.str3 = private unnamed_addr constant [15 x i8] c"setCoeffs_loop\00", align 1 ; [#uses=1 type=[15 x i8]*]
@.str2 = private unnamed_addr constant [6 x i8] c"eq_io\00", align 1 ; [#uses=5 type=[6 x i8]*]
@.str1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=25 type=[1 x i8]*]
@.str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=5 type=[10 x i8]*]

; [#uses=15]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=0]
define void @equalizer(float* %y, float %x, i32 %mode, [5 x [6 x float]]* %coeffs) nounwind {
codeRepl:
  call void (...)* @_ssdm_op_SpecBitsMap(float* %y) nounwind, !map !72
  call void (...)* @_ssdm_op_SpecBitsMap(float %x) nounwind, !map !78
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %mode) nounwind, !map !84
  call void (...)* @_ssdm_op_SpecBitsMap([5 x [6 x float]]* %coeffs) nounwind, !map !88
  call void (...)* @_ssdm_op_SpecTopModule([10 x i8]* @equalizer.str) nounwind
  call void @llvm.dbg.value(metadata !{float* %y}, i64 0, metadata !95), !dbg !96 ; [debug line = 3:24] [debug variable = y]
  call void @llvm.dbg.value(metadata !{float %x}, i64 0, metadata !97), !dbg !98 ; [debug line = 3:34] [debug variable = x]
  call void @llvm.dbg.value(metadata !{i32 %mode}, i64 0, metadata !99), !dbg !100 ; [debug line = 3:41] [debug variable = mode]
  call void @llvm.dbg.value(metadata !{[5 x [6 x float]]* %coeffs}, i64 0, metadata !101), !dbg !102 ; [debug line = 3:54] [debug variable = coeffs]
  call void (...)* @_ssdm_op_SpecInterface([5 x [6 x float]]* %coeffs, [10 x i8]* @.str, i32 0, i32 0, [1 x i8]* @.str1, i32 0, i32 0, [6 x i8]* @.str2, [1 x i8]* @.str1, [1 x i8]* @.str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @.str1, [1 x i8]* @.str1) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32 %mode, [10 x i8]* @.str, i32 0, i32 0, [1 x i8]* @.str1, i32 0, i32 0, [6 x i8]* @.str2, [1 x i8]* @.str1, [1 x i8]* @.str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @.str1, [1 x i8]* @.str1) nounwind, !dbg !103 ; [debug line = 4:1]
  call void (...)* @_ssdm_op_SpecInterface(float %x, [10 x i8]* @.str, i32 0, i32 0, [1 x i8]* @.str1, i32 0, i32 0, [6 x i8]* @.str2, [1 x i8]* @.str1, [1 x i8]* @.str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @.str1, [1 x i8]* @.str1) nounwind, !dbg !103 ; [debug line = 4:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @.str, i32 0, i32 0, [1 x i8]* @.str1, i32 0, i32 0, [6 x i8]* @.str2, [1 x i8]* @.str1, [1 x i8]* @.str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @.str1, [1 x i8]* @.str1) nounwind, !dbg !103 ; [debug line = 4:1]
  call void (...)* @_ssdm_op_SpecInterface(float* %y, [10 x i8]* @.str, i32 0, i32 0, [1 x i8]* @.str1, i32 0, i32 0, [6 x i8]* @.str2, [1 x i8]* @.str1, [1 x i8]* @.str1, i32 0, i32 0, i32 0, i32 0, [1 x i8]* @.str1, [1 x i8]* @.str1) nounwind, !dbg !103 ; [debug line = 4:1]
  %tmp.1 = icmp eq i32 %mode, 1, !dbg !105        ; [#uses=1 type=i1] [debug line = 5:3]
  br i1 %tmp.1, label %.preheader4.preheader, label %.preheader.preheader, !dbg !105 ; [debug line = 5:3]

.preheader4.preheader:                            ; preds = %codeRepl
  br label %.preheader4, !dbg !106                ; [debug line = 34:26@6:9]

.preheader.preheader:                             ; preds = %codeRepl
  br label %.preheader, !dbg !111                 ; [debug line = 25:14@8:4]

.preheader4:                                      ; preds = %1, %.preheader4.preheader
  %temp.i = phi float [ %acc, %1 ], [ %x, %.preheader4.preheader ] ; [#uses=3 type=float]
  %i.i = phi i3 [ %i, %1 ], [ 0, %.preheader4.preheader ] ; [#uses=3 type=i3]
  %i.i.cast3 = zext i3 %i.i to i32, !dbg !106     ; [#uses=10 type=i32] [debug line = 34:26@6:9]
  %exitcond.i = icmp eq i3 %i.i, -3, !dbg !106    ; [#uses=1 type=i1] [debug line = 34:26@6:9]
  %0 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 5, i64 5, i64 5) nounwind ; [#uses=0 type=i32]
  br i1 %exitcond.i, label %filter.exit, label %1, !dbg !106 ; [debug line = 34:26@6:9]

; <label>:1                                       ; preds = %.preheader4
  call void (...)* @_ssdm_op_SpecLoopName([12 x i8]* @.str4) nounwind, !dbg !117 ; [debug line = 34:45@6:9]
  %iir.coeff_array.addr = getelementptr [5 x [6 x float]]* @iir.coeff_array, i32 0, i32 %i.i.cast3, i32 0, !dbg !119 ; [#uses=1 type=float*] [debug line = 36:4@6:9]
  %b0 = load float* %iir.coeff_array.addr, align 8, !dbg !119 ; [#uses=1 type=float] [debug line = 36:4@6:9]
  call void @llvm.dbg.value(metadata !{float %b0}, i64 0, metadata !120) nounwind, !dbg !119 ; [debug line = 36:4@6:9] [debug variable = b0]
  %iir.coeff_array.addr.1 = getelementptr [5 x [6 x float]]* @iir.coeff_array, i32 0, i32 %i.i.cast3, i32 1, !dbg !121 ; [#uses=1 type=float*] [debug line = 37:4@6:9]
  %b1 = load float* %iir.coeff_array.addr.1, align 4, !dbg !121 ; [#uses=1 type=float] [debug line = 37:4@6:9]
  call void @llvm.dbg.value(metadata !{float %b1}, i64 0, metadata !122) nounwind, !dbg !121 ; [debug line = 37:4@6:9] [debug variable = b1]
  %iir.coeff_array.addr.2 = getelementptr [5 x [6 x float]]* @iir.coeff_array, i32 0, i32 %i.i.cast3, i32 2, !dbg !123 ; [#uses=1 type=float*] [debug line = 38:4@6:9]
  %b2 = load float* %iir.coeff_array.addr.2, align 8, !dbg !123 ; [#uses=1 type=float] [debug line = 38:4@6:9]
  call void @llvm.dbg.value(metadata !{float %b2}, i64 0, metadata !124) nounwind, !dbg !123 ; [debug line = 38:4@6:9] [debug variable = b2]
  %iir.coeff_array.addr.3 = getelementptr [5 x [6 x float]]* @iir.coeff_array, i32 0, i32 %i.i.cast3, i32 3, !dbg !125 ; [#uses=1 type=float*] [debug line = 39:4@6:9]
  %a0 = load float* %iir.coeff_array.addr.3, align 4, !dbg !125 ; [#uses=5 type=float] [debug line = 39:4@6:9]
  call void @llvm.dbg.value(metadata !{float %a0}, i64 0, metadata !126) nounwind, !dbg !125 ; [debug line = 39:4@6:9] [debug variable = a0]
  %iir.coeff_array.addr.4 = getelementptr [5 x [6 x float]]* @iir.coeff_array, i32 0, i32 %i.i.cast3, i32 4, !dbg !127 ; [#uses=1 type=float*] [debug line = 40:4@6:9]
  %a1 = load float* %iir.coeff_array.addr.4, align 8, !dbg !127 ; [#uses=1 type=float] [debug line = 40:4@6:9]
  call void @llvm.dbg.value(metadata !{float %a1}, i64 0, metadata !128) nounwind, !dbg !127 ; [debug line = 40:4@6:9] [debug variable = a1]
  %iir.coeff_array.addr.5 = getelementptr [5 x [6 x float]]* @iir.coeff_array, i32 0, i32 %i.i.cast3, i32 5, !dbg !129 ; [#uses=1 type=float*] [debug line = 41:4@6:9]
  %a2 = load float* %iir.coeff_array.addr.5, align 4, !dbg !129 ; [#uses=1 type=float] [debug line = 41:4@6:9]
  call void @llvm.dbg.value(metadata !{float %a2}, i64 0, metadata !130) nounwind, !dbg !129 ; [debug line = 41:4@6:9] [debug variable = a2]
  %iir.x.1.addr = getelementptr [5 x float]* @iir.x.1, i32 0, i32 %i.i.cast3, !dbg !131 ; [#uses=2 type=float*] [debug line = 43:4@6:9]
  %iir.x.1.load = load float* %iir.x.1.addr, align 4, !dbg !131 ; [#uses=1 type=float] [debug line = 43:4@6:9]
  %iir.x.0.addr = getelementptr [5 x float]* @iir.x.0, i32 0, i32 %i.i.cast3, !dbg !132 ; [#uses=2 type=float*] [debug line = 44:4@6:9]
  %iir.x.0.load = load float* %iir.x.0.addr, align 4, !dbg !132 ; [#uses=2 type=float] [debug line = 44:4@6:9]
  store float %iir.x.0.load, float* %iir.x.1.addr, align 4, !dbg !132 ; [debug line = 44:4@6:9]
  store float %temp.i, float* %iir.x.0.addr, align 4, !dbg !133 ; [debug line = 45:4@6:9]
  %tmp.i = fmul float %b0, %temp.i, !dbg !134     ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %tmp.3.i = fdiv float %tmp.i, %a0, !dbg !134    ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %tmp.4.i = fmul float %b1, %iir.x.0.load, !dbg !134 ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %tmp.5.i = fdiv float %tmp.4.i, %a0, !dbg !134  ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %tmp.6.i = fadd float %tmp.3.i, %tmp.5.i, !dbg !134 ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %tmp.7.i = fmul float %b2, %iir.x.1.load, !dbg !134 ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %tmp.8.i = fdiv float %tmp.7.i, %a0, !dbg !134  ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %tmp.9.i = fadd float %tmp.6.i, %tmp.8.i, !dbg !134 ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %iir.y.1.addr = getelementptr [5 x float]* @iir.y.1, i32 0, i32 %i.i.cast3, !dbg !134 ; [#uses=2 type=float*] [debug line = 47:4@6:9]
  %iir.y.1.load = load float* %iir.y.1.addr, align 4, !dbg !134 ; [#uses=2 type=float] [debug line = 47:4@6:9]
  %tmp..i = fmul float %a1, %iir.y.1.load, !dbg !134 ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %tmp.1.i = fdiv float %tmp..i, %a0, !dbg !134   ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %tmp.2.i = fsub float %tmp.9.i, %tmp.1.i, !dbg !134 ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %iir.y.2.addr = getelementptr [5 x float]* @iir.y.2, i32 0, i32 %i.i.cast3, !dbg !134 ; [#uses=2 type=float*] [debug line = 47:4@6:9]
  %iir.y.2.load = load float* %iir.y.2.addr, align 4, !dbg !134 ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %tmp.10.i = fmul float %a2, %iir.y.2.load, !dbg !134 ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %tmp.11.i = fdiv float %tmp.10.i, %a0, !dbg !134 ; [#uses=1 type=float] [debug line = 47:4@6:9]
  %acc = fsub float %tmp.2.i, %tmp.11.i, !dbg !134 ; [#uses=2 type=float] [debug line = 47:4@6:9]
  call void @llvm.dbg.value(metadata !{float %acc}, i64 0, metadata !135) nounwind, !dbg !134 ; [debug line = 47:4@6:9] [debug variable = acc]
  store float %iir.y.1.load, float* %iir.y.2.addr, align 4, !dbg !136 ; [debug line = 51:4@6:9]
  store float %acc, float* %iir.y.1.addr, align 4, !dbg !137 ; [debug line = 52:4@6:9]
  call void @llvm.dbg.value(metadata !{float %acc}, i64 0, metadata !138) nounwind, !dbg !139 ; [debug line = 53:4@6:9] [debug variable = temp]
  %i = add i3 %i.i, 1, !dbg !140                  ; [#uses=1 type=i3] [debug line = 34:40@6:9]
  call void @llvm.dbg.value(metadata !{i3 %i}, i64 0, metadata !141) nounwind, !dbg !140 ; [debug line = 34:40@6:9] [debug variable = i]
  br label %.preheader4, !dbg !140                ; [debug line = 34:40@6:9]

filter.exit:                                      ; preds = %.preheader4
  %temp.i.lcssa = phi float [ %temp.i, %.preheader4 ] ; [#uses=1 type=float]
  store float %temp.i.lcssa, float* %y, align 4, !dbg !110 ; [debug line = 6:9]
  br label %setCoeffs.exit, !dbg !110             ; [debug line = 6:9]

.preheader:                                       ; preds = %5, %.preheader.preheader
  %i.i1 = phi i3 [ %i.1, %5 ], [ 0, %.preheader.preheader ] ; [#uses=3 type=i3]
  %i.i1.cast2 = zext i3 %i.i1 to i32, !dbg !111   ; [#uses=2 type=i32] [debug line = 25:14@8:4]
  %exitcond1.i = icmp eq i3 %i.i1, -3, !dbg !111  ; [#uses=1 type=i1] [debug line = 25:14@8:4]
  %2 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 5, i64 5, i64 5) nounwind ; [#uses=0 type=i32]
  br i1 %exitcond1.i, label %setCoeffs.exit.loopexit, label %.preheader.i.preheader, !dbg !111 ; [debug line = 25:14@8:4]

.preheader.i.preheader:                           ; preds = %.preheader
  br label %.preheader.i, !dbg !142               ; [debug line = 26:31@8:4]

.preheader.i:                                     ; preds = %4, %.preheader.i.preheader
  %j.i = phi i3 [ %j, %4 ], [ 0, %.preheader.i.preheader ] ; [#uses=3 type=i3]
  %j.i.cast1 = zext i3 %j.i to i32, !dbg !142     ; [#uses=2 type=i32] [debug line = 26:31@8:4]
  %exitcond.i2 = icmp eq i3 %j.i, -2, !dbg !142   ; [#uses=1 type=i1] [debug line = 26:31@8:4]
  %3 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 6, i64 6, i64 6) nounwind ; [#uses=0 type=i32]
  br i1 %exitcond.i2, label %5, label %4, !dbg !142 ; [debug line = 26:31@8:4]

; <label>:4                                       ; preds = %.preheader.i
  call void (...)* @_ssdm_op_SpecLoopName([15 x i8]* @.str3) nounwind, !dbg !145 ; [debug line = 26:46@8:4]
  %coeffs.addr = getelementptr [5 x [6 x float]]* %coeffs, i32 0, i32 %i.i1.cast2, i32 %j.i.cast1, !dbg !147 ; [#uses=1 type=float*] [debug line = 27:5@8:4]
  %coeffs.load = load float* %coeffs.addr, align 4, !dbg !147 ; [#uses=1 type=float] [debug line = 27:5@8:4]
  %iir.coeff_array.addr.6 = getelementptr [5 x [6 x float]]* @iir.coeff_array, i32 0, i32 %i.i1.cast2, i32 %j.i.cast1, !dbg !147 ; [#uses=1 type=float*] [debug line = 27:5@8:4]
  store float %coeffs.load, float* %iir.coeff_array.addr.6, align 4, !dbg !147 ; [debug line = 27:5@8:4]
  %j = add i3 %j.i, 1, !dbg !148                  ; [#uses=1 type=i3] [debug line = 26:40@8:4]
  call void @llvm.dbg.value(metadata !{i3 %j}, i64 0, metadata !149) nounwind, !dbg !148 ; [debug line = 26:40@8:4] [debug variable = j]
  br label %.preheader.i, !dbg !148               ; [debug line = 26:40@8:4]

; <label>:5                                       ; preds = %.preheader.i
  %i.1 = add i3 %i.i1, 1, !dbg !150               ; [#uses=1 type=i3] [debug line = 25:28@8:4]
  call void @llvm.dbg.value(metadata !{i3 %i.1}, i64 0, metadata !151) nounwind, !dbg !150 ; [debug line = 25:28@8:4] [debug variable = i]
  br label %.preheader, !dbg !150                 ; [debug line = 25:28@8:4]

setCoeffs.exit.loopexit:                          ; preds = %.preheader
  br label %setCoeffs.exit

setCoeffs.exit:                                   ; preds = %setCoeffs.exit.loopexit, %filter.exit
  ret void, !dbg !152                             ; [debug line = 10:1]
}

; [#uses=1]
declare void @_ssdm_op_SpecTopModule(...)

; [#uses=3]
declare i32 @_ssdm_op_SpecLoopTripCount(...)

; [#uses=2]
declare void @_ssdm_op_SpecLoopName(...) nounwind

; [#uses=5]
declare void @_ssdm_op_SpecInterface(...) nounwind

; [#uses=4]
declare void @_ssdm_op_SpecBitsMap(...)

!opencl.kernels = !{!0, !7, !13, !17, !17}
!hls.encrypted.func = !{}
!llvm.map.gv = !{}
!llvm.dbg.cu = !{!23}

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
!23 = metadata !{i32 786449, i32 0, i32 4, metadata !"C:/Users/marti/Documents/GitHub/Embedded-Systems-Course/project/equalizer/equalizer/.autopilot/db/iir.pragma.2.cpp", metadata !"C:\5CUsers\5Cmarti\5CDocuments\5CGitHub\5CEmbedded-Systems-Course\5Cproject", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, null, null, null, metadata !24} ; [ DW_TAG_compile_unit ]
!24 = metadata !{metadata !25}
!25 = metadata !{metadata !26, metadata !60, metadata !63, metadata !66}
!26 = metadata !{i32 790546, i32 0, null, metadata !"iir.coeff_array", metadata !"iir.coeff_array", metadata !"iir.coeff_array", metadata !27, i32 4, metadata !28, i32 1, i32 1, [5 x [6 x float]]* @iir.coeff_array} ; [ DW_TAG_variable_field ]
!27 = metadata !{i32 786473, metadata !"equalizer/iir.cpp", metadata !"C:\5CUsers\5Cmarti\5CDocuments\5CGitHub\5CEmbedded-Systems-Course\5Cproject", null} ; [ DW_TAG_file_type ]
!28 = metadata !{i32 786438, null, metadata !"IIRFilter", metadata !29, i32 8, i64 960, i64 32, i32 0, i32 0, null, metadata !30, i32 0, null, null} ; [ DW_TAG_class_field_type ]
!29 = metadata !{i32 786473, metadata !"equalizer/iir.h", metadata !"C:\5CUsers\5Cmarti\5CDocuments\5CGitHub\5CEmbedded-Systems-Course\5Cproject", null} ; [ DW_TAG_file_type ]
!30 = metadata !{metadata !31}
!31 = metadata !{i32 786445, metadata !32, metadata !"coeff_array", metadata !29, i32 12, i64 960, i64 32, i64 960, i32 0, metadata !58} ; [ DW_TAG_member ]
!32 = metadata !{i32 786434, null, metadata !"IIRFilter", metadata !29, i32 8, i64 1920, i64 32, i32 0, i32 0, null, metadata !33, i32 0, null, null} ; [ DW_TAG_class_type ]
!33 = metadata !{metadata !34, metadata !41, metadata !31, metadata !42, metadata !48, metadata !55}
!34 = metadata !{i32 786445, metadata !32, metadata !"x", metadata !29, i32 10, i64 480, i64 32, i64 0, i32 0, metadata !35} ; [ DW_TAG_member ]
!35 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 480, i64 32, i32 0, i32 0, metadata !36, metadata !38, i32 0, i32 0} ; [ DW_TAG_array_type ]
!36 = metadata !{i32 786454, null, metadata !"data_t", metadata !27, i32 2, i64 0, i64 0, i64 0, i32 0, metadata !37} ; [ DW_TAG_typedef ]
!37 = metadata !{i32 786468, null, metadata !"float", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 4} ; [ DW_TAG_base_type ]
!38 = metadata !{metadata !39, metadata !40}
!39 = metadata !{i32 786465, i64 0, i64 4}        ; [ DW_TAG_subrange_type ]
!40 = metadata !{i32 786465, i64 0, i64 2}        ; [ DW_TAG_subrange_type ]
!41 = metadata !{i32 786445, metadata !32, metadata !"y", metadata !29, i32 11, i64 480, i64 32, i64 480, i32 0, metadata !35} ; [ DW_TAG_member ]
!42 = metadata !{i32 786478, i32 0, metadata !32, metadata !"IIRFilter", metadata !"IIRFilter", metadata !"", metadata !29, i32 13, metadata !43, i1 false, i1 false, i32 0, i32 0, null, i32 256, i1 false, null, null, i32 0, metadata !46, i32 13} ; [ DW_TAG_subprogram ]
!43 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !44, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!44 = metadata !{null, metadata !45}
!45 = metadata !{i32 786447, i32 0, metadata !"", i32 0, i32 0, i64 32, i64 32, i64 0, i32 64, metadata !32} ; [ DW_TAG_pointer_type ]
!46 = metadata !{metadata !47}
!47 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!48 = metadata !{i32 786478, i32 0, metadata !32, metadata !"setCoeffs", metadata !"setCoeffs", metadata !"_ZN9IIRFilter9setCoeffsEPA6_f", metadata !29, i32 24, metadata !49, i1 false, i1 false, i32 0, i32 0, null, i32 256, i1 false, null, null, i32 0, metadata !46, i32 24} ; [ DW_TAG_subprogram ]
!49 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !50, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!50 = metadata !{null, metadata !45, metadata !51}
!51 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !52} ; [ DW_TAG_pointer_type ]
!52 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 192, i64 32, i32 0, i32 0, metadata !36, metadata !53, i32 0, i32 0} ; [ DW_TAG_array_type ]
!53 = metadata !{metadata !54}
!54 = metadata !{i32 786465, i64 0, i64 5}        ; [ DW_TAG_subrange_type ]
!55 = metadata !{i32 786478, i32 0, metadata !32, metadata !"filter", metadata !"filter", metadata !"_ZN9IIRFilter6filterEf", metadata !29, i32 31, metadata !56, i1 false, i1 false, i32 0, i32 0, null, i32 256, i1 false, null, null, i32 0, metadata !46, i32 31} ; [ DW_TAG_subprogram ]
!56 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !57, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!57 = metadata !{metadata !36, metadata !45, metadata !36}
!58 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 960, i64 32, i32 0, i32 0, metadata !36, metadata !59, i32 0, i32 0} ; [ DW_TAG_array_type ]
!59 = metadata !{metadata !39, metadata !54}
!60 = metadata !{i32 790546, i32 0, null, metadata !"iir.y", metadata !"iir.y", metadata !"iir.y", metadata !27, i32 4, metadata !61, i32 1, i32 1, null} ; [ DW_TAG_variable_field ]
!61 = metadata !{i32 786438, null, metadata !"IIRFilter", metadata !29, i32 8, i64 480, i64 32, i32 0, i32 0, null, metadata !62, i32 0, null, null} ; [ DW_TAG_class_field_type ]
!62 = metadata !{metadata !41}
!63 = metadata !{i32 790546, i32 0, null, metadata !"iir.x", metadata !"iir.x", metadata !"iir.x", metadata !27, i32 4, metadata !64, i32 1, i32 1, null} ; [ DW_TAG_variable_field ]
!64 = metadata !{i32 786438, null, metadata !"IIRFilter", metadata !29, i32 8, i64 480, i64 32, i32 0, i32 0, null, metadata !65, i32 0, null, null} ; [ DW_TAG_class_field_type ]
!65 = metadata !{metadata !34}
!66 = metadata !{i32 786484, i32 0, metadata !67, metadata !"iir", metadata !"iir", metadata !"", metadata !27, i32 4, metadata !32, i32 1, i32 1, null} ; [ DW_TAG_variable ]
!67 = metadata !{i32 786478, i32 0, metadata !27, metadata !"equalizer", metadata !"equalizer", metadata !"_Z9equalizerPffiPA6_f", metadata !27, i32 3, metadata !68, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, null, metadata !46, i32 3} ; [ DW_TAG_subprogram ]
!68 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !69, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!69 = metadata !{null, metadata !70, metadata !36, metadata !71, metadata !51}
!70 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !36} ; [ DW_TAG_pointer_type ]
!71 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!72 = metadata !{metadata !73}
!73 = metadata !{i32 0, i32 31, metadata !74}
!74 = metadata !{metadata !75}
!75 = metadata !{metadata !"y", metadata !76, metadata !"float", i32 0, i32 31}
!76 = metadata !{metadata !77}
!77 = metadata !{i32 0, i32 0, i32 1}
!78 = metadata !{metadata !79}
!79 = metadata !{i32 0, i32 31, metadata !80}
!80 = metadata !{metadata !81}
!81 = metadata !{metadata !"x", metadata !82, metadata !"float", i32 0, i32 31}
!82 = metadata !{metadata !83}
!83 = metadata !{i32 0, i32 0, i32 0}
!84 = metadata !{metadata !85}
!85 = metadata !{i32 0, i32 31, metadata !86}
!86 = metadata !{metadata !87}
!87 = metadata !{metadata !"mode", metadata !82, metadata !"int", i32 0, i32 31}
!88 = metadata !{metadata !89}
!89 = metadata !{i32 0, i32 31, metadata !90}
!90 = metadata !{metadata !91}
!91 = metadata !{metadata !"coeffs", metadata !92, metadata !"float", i32 0, i32 31}
!92 = metadata !{metadata !93, metadata !94}
!93 = metadata !{i32 0, i32 4, i32 1}
!94 = metadata !{i32 0, i32 5, i32 1}
!95 = metadata !{i32 786689, metadata !67, metadata !"y", metadata !27, i32 16777219, metadata !70, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!96 = metadata !{i32 3, i32 24, metadata !67, null}
!97 = metadata !{i32 786689, metadata !67, metadata !"x", metadata !27, i32 33554435, metadata !36, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!98 = metadata !{i32 3, i32 34, metadata !67, null}
!99 = metadata !{i32 786689, metadata !67, metadata !"mode", metadata !27, i32 50331651, metadata !71, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!100 = metadata !{i32 3, i32 41, metadata !67, null}
!101 = metadata !{i32 786689, metadata !67, metadata !"coeffs", null, i32 3, metadata !58, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!102 = metadata !{i32 3, i32 54, metadata !67, null}
!103 = metadata !{i32 4, i32 1, metadata !104, null}
!104 = metadata !{i32 786443, metadata !67, i32 3, i32 74, metadata !27, i32 0} ; [ DW_TAG_lexical_block ]
!105 = metadata !{i32 5, i32 3, metadata !104, null}
!106 = metadata !{i32 34, i32 26, metadata !107, metadata !110}
!107 = metadata !{i32 786443, metadata !108, i32 34, i32 15, metadata !29, i32 8} ; [ DW_TAG_lexical_block ]
!108 = metadata !{i32 786443, metadata !109, i32 31, i32 30, metadata !29, i32 7} ; [ DW_TAG_lexical_block ]
!109 = metadata !{i32 786478, i32 0, null, metadata !"filter", metadata !"filter", metadata !"_ZN9IIRFilter6filterEf", metadata !29, i32 31, metadata !56, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, metadata !55, metadata !46, i32 31} ; [ DW_TAG_subprogram ]
!110 = metadata !{i32 6, i32 9, metadata !104, null}
!111 = metadata !{i32 25, i32 14, metadata !112, metadata !115}
!112 = metadata !{i32 786443, metadata !113, i32 25, i32 3, metadata !29, i32 3} ; [ DW_TAG_lexical_block ]
!113 = metadata !{i32 786443, metadata !114, i32 24, i32 43, metadata !29, i32 2} ; [ DW_TAG_lexical_block ]
!114 = metadata !{i32 786478, i32 0, null, metadata !"setCoeffs", metadata !"setCoeffs", metadata !"_ZN9IIRFilter9setCoeffsEPA6_f", metadata !29, i32 24, metadata !49, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, metadata !48, metadata !46, i32 24} ; [ DW_TAG_subprogram ]
!115 = metadata !{i32 8, i32 4, metadata !116, null}
!116 = metadata !{i32 786443, metadata !104, i32 7, i32 8, metadata !27, i32 1} ; [ DW_TAG_lexical_block ]
!117 = metadata !{i32 34, i32 45, metadata !118, metadata !110}
!118 = metadata !{i32 786443, metadata !107, i32 34, i32 44, metadata !29, i32 9} ; [ DW_TAG_lexical_block ]
!119 = metadata !{i32 36, i32 4, metadata !118, metadata !110}
!120 = metadata !{i32 786688, metadata !108, metadata !"b0", metadata !29, i32 32, metadata !36, i32 0, metadata !110} ; [ DW_TAG_auto_variable ]
!121 = metadata !{i32 37, i32 4, metadata !118, metadata !110}
!122 = metadata !{i32 786688, metadata !108, metadata !"b1", metadata !29, i32 32, metadata !36, i32 0, metadata !110} ; [ DW_TAG_auto_variable ]
!123 = metadata !{i32 38, i32 4, metadata !118, metadata !110}
!124 = metadata !{i32 786688, metadata !108, metadata !"b2", metadata !29, i32 32, metadata !36, i32 0, metadata !110} ; [ DW_TAG_auto_variable ]
!125 = metadata !{i32 39, i32 4, metadata !118, metadata !110}
!126 = metadata !{i32 786688, metadata !108, metadata !"a0", metadata !29, i32 32, metadata !36, i32 0, metadata !110} ; [ DW_TAG_auto_variable ]
!127 = metadata !{i32 40, i32 4, metadata !118, metadata !110}
!128 = metadata !{i32 786688, metadata !108, metadata !"a1", metadata !29, i32 32, metadata !36, i32 0, metadata !110} ; [ DW_TAG_auto_variable ]
!129 = metadata !{i32 41, i32 4, metadata !118, metadata !110}
!130 = metadata !{i32 786688, metadata !108, metadata !"a2", metadata !29, i32 32, metadata !36, i32 0, metadata !110} ; [ DW_TAG_auto_variable ]
!131 = metadata !{i32 43, i32 4, metadata !118, metadata !110}
!132 = metadata !{i32 44, i32 4, metadata !118, metadata !110}
!133 = metadata !{i32 45, i32 4, metadata !118, metadata !110}
!134 = metadata !{i32 47, i32 4, metadata !118, metadata !110}
!135 = metadata !{i32 786688, metadata !108, metadata !"acc", metadata !29, i32 32, metadata !36, i32 0, metadata !110} ; [ DW_TAG_auto_variable ]
!136 = metadata !{i32 51, i32 4, metadata !118, metadata !110}
!137 = metadata !{i32 52, i32 4, metadata !118, metadata !110}
!138 = metadata !{i32 786688, metadata !108, metadata !"temp", metadata !29, i32 32, metadata !36, i32 0, metadata !110} ; [ DW_TAG_auto_variable ]
!139 = metadata !{i32 53, i32 4, metadata !118, metadata !110}
!140 = metadata !{i32 34, i32 40, metadata !107, metadata !110}
!141 = metadata !{i32 786688, metadata !107, metadata !"i", metadata !29, i32 34, metadata !71, i32 0, metadata !110} ; [ DW_TAG_auto_variable ]
!142 = metadata !{i32 26, i32 31, metadata !143, metadata !115}
!143 = metadata !{i32 786443, metadata !144, i32 26, i32 19, metadata !29, i32 5} ; [ DW_TAG_lexical_block ]
!144 = metadata !{i32 786443, metadata !112, i32 25, i32 33, metadata !29, i32 4} ; [ DW_TAG_lexical_block ]
!145 = metadata !{i32 26, i32 46, metadata !146, metadata !115}
!146 = metadata !{i32 786443, metadata !143, i32 26, i32 45, metadata !29, i32 6} ; [ DW_TAG_lexical_block ]
!147 = metadata !{i32 27, i32 5, metadata !146, metadata !115}
!148 = metadata !{i32 26, i32 40, metadata !143, metadata !115}
!149 = metadata !{i32 786688, metadata !143, metadata !"j", metadata !29, i32 26, metadata !71, i32 0, metadata !115} ; [ DW_TAG_auto_variable ]
!150 = metadata !{i32 25, i32 28, metadata !112, metadata !115}
!151 = metadata !{i32 786688, metadata !112, metadata !"i", metadata !29, i32 25, metadata !71, i32 0, metadata !115} ; [ DW_TAG_auto_variable ]
!152 = metadata !{i32 10, i32 1, metadata !104, null}
