; ModuleID = 'C:/Users/marti/Documents/EmbeddedSystems/project/equalizer/equalizer/.autopilot/db/a.g.1.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

%class.IIRFilter.0 = type { [5 x [3 x float]], [5 x [3 x float]], [5 x [6 x float]] }

@iir = internal global %class.IIRFilter.0 zeroinitializer, align 4 ; [#uses=12 type=%class.IIRFilter.0*]
@equalizer.str = internal unnamed_addr constant [10 x i8] c"equalizer\00" ; [#uses=1 type=[10 x i8]*]
@.str4 = private unnamed_addr constant [12 x i8] c"filter_loop\00", align 1 ; [#uses=1 type=[12 x i8]*]
@.str3 = private unnamed_addr constant [15 x i8] c"setCoeffs_loop\00", align 1 ; [#uses=1 type=[15 x i8]*]
@.str2 = private unnamed_addr constant [6 x i8] c"eq_io\00", align 1 ; [#uses=1 type=[6 x i8]*]
@.str1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=1 type=[1 x i8]*]
@.str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=1 type=[10 x i8]*]

; [#uses=17]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=0]
define void @equalizer(float* %y, float %x, i32 %mode, [6 x float]* %coeffs) nounwind {
codeRepl:
  call void (...)* @_ssdm_op_SpecTopModule([10 x i8]* @equalizer.str) nounwind
  call void @llvm.dbg.value(metadata !{float* %y}, i64 0, metadata !71), !dbg !72 ; [debug line = 3:24] [debug variable = y]
  call void @llvm.dbg.value(metadata !{float %x}, i64 0, metadata !73), !dbg !74 ; [debug line = 3:34] [debug variable = x]
  call void @llvm.dbg.value(metadata !{i32 %mode}, i64 0, metadata !75), !dbg !76 ; [debug line = 3:41] [debug variable = mode]
  call void @llvm.dbg.value(metadata !{[6 x float]* %coeffs}, i64 0, metadata !77), !dbg !78 ; [debug line = 3:54] [debug variable = coeffs]
  call void (...)* @_ssdm_SpecArrayDimSize([6 x float]* %coeffs, i32 5) nounwind, !dbg !79 ; [debug line = 3:75]
  call void (...)* @_ssdm_op_SpecInterface([6 x float]* %coeffs, i8* getelementptr inbounds ([10 x i8]* @.str, i32 0, i32 0), i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i8* getelementptr inbounds ([6 x i8]* @.str2, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0)) nounwind, !dbg !81 ; [debug line = 4:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 %mode, i8* getelementptr inbounds ([10 x i8]* @.str, i32 0, i32 0), i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i8* getelementptr inbounds ([6 x i8]* @.str2, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0)) nounwind, !dbg !81 ; [debug line = 4:1]
  %tmp = fpext float %x to double, !dbg !81       ; [#uses=1 type=double] [debug line = 4:1]
  call void (...)* @_ssdm_op_SpecInterface(double %tmp, i8* getelementptr inbounds ([10 x i8]* @.str, i32 0, i32 0), i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i8* getelementptr inbounds ([6 x i8]* @.str2, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0)) nounwind, !dbg !81 ; [debug line = 4:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 0, i8* getelementptr inbounds ([10 x i8]* @.str, i32 0, i32 0), i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i8* getelementptr inbounds ([6 x i8]* @.str2, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0)) nounwind, !dbg !81 ; [debug line = 4:1]
  call void (...)* @_ssdm_op_SpecInterface(float* %y, i8* getelementptr inbounds ([10 x i8]* @.str, i32 0, i32 0), i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i8* getelementptr inbounds ([6 x i8]* @.str2, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0)) nounwind, !dbg !81 ; [debug line = 4:1]
  %tmp.1 = icmp eq i32 %mode, 1, !dbg !82         ; [#uses=1 type=i1] [debug line = 5:3]
  br i1 %tmp.1, label %0, label %1, !dbg !82      ; [debug line = 5:3]

; <label>:0                                       ; preds = %codeRepl
  %tmp.2 = call fastcc float @"IIRFilter::filter"(float %x), !dbg !83 ; [#uses=1 type=float] [debug line = 6:9]
  store float %tmp.2, float* %y, align 4, !dbg !83 ; [debug line = 6:9]
  br label %2, !dbg !83                           ; [debug line = 6:9]

; <label>:1                                       ; preds = %codeRepl
  call fastcc void @"IIRFilter::setCoeffs"([6 x float]* %coeffs), !dbg !84 ; [debug line = 8:4]
  br label %2

; <label>:2                                       ; preds = %1, %0
  ret void, !dbg !86                              ; [debug line = 10:1]
}

; [#uses=1]
declare void @_ssdm_op_SpecTopModule(...)

; [#uses=2]
declare i32 @_ssdm_op_SpecRegionEnd(...)

; [#uses=2]
declare i32 @_ssdm_op_SpecRegionBegin(...)

; [#uses=2]
declare void @_ssdm_op_SpecLoopName(...) nounwind

; [#uses=5]
declare void @_ssdm_op_SpecInterface(...) nounwind

; [#uses=16]
declare void @_ssdm_SpecKeepArrayLoad(...)

; [#uses=2]
declare void @_ssdm_SpecArrayDimSize(...) nounwind

; [#uses=1]
define internal fastcc void @"IIRFilter::setCoeffs"([6 x float]* %coefs) nounwind align 2 {
  call void @llvm.dbg.value(metadata !{[6 x float]* %coefs}, i64 0, metadata !87), !dbg !88 ; [debug line = 24:24] [debug variable = coefs]
  call void (...)* @_ssdm_SpecArrayDimSize([6 x float]* %coefs, i32 5) nounwind, !dbg !89 ; [debug line = 24:44]
  br label %1, !dbg !91                           ; [debug line = 25:14]

; <label>:1                                       ; preds = %3, %0
  %i = phi i32 [ 0, %0 ], [ %i.1, %3 ]            ; [#uses=4 type=i32]
  %exitcond1 = icmp eq i32 %i, 5, !dbg !91        ; [#uses=1 type=i1] [debug line = 25:14]
  br i1 %exitcond1, label %4, label %.preheader.preheader, !dbg !91 ; [debug line = 25:14]

.preheader.preheader:                             ; preds = %1
  br label %.preheader, !dbg !93                  ; [debug line = 26:31]

.preheader:                                       ; preds = %2, %.preheader.preheader
  %j = phi i32 [ %j.1, %2 ], [ 0, %.preheader.preheader ] ; [#uses=4 type=i32]
  %exitcond = icmp eq i32 %j, 6, !dbg !93         ; [#uses=1 type=i1] [debug line = 26:31]
  br i1 %exitcond, label %3, label %2, !dbg !93   ; [debug line = 26:31]

; <label>:2                                       ; preds = %.preheader
  call void (...)* @_ssdm_op_SpecLoopName(i8* getelementptr inbounds ([15 x i8]* @.str3, i32 0, i32 0)) nounwind, !dbg !96 ; [debug line = 26:46]
  %rbegin = call i32 (...)* @_ssdm_op_SpecRegionBegin(i8* getelementptr inbounds ([15 x i8]* @.str3, i32 0, i32 0)) nounwind, !dbg !96 ; [#uses=1 type=i32] [debug line = 26:46]
  %coefs.addr = getelementptr inbounds [6 x float]* %coefs, i32 %i, i32 %j, !dbg !98 ; [#uses=1 type=float*] [debug line = 27:5]
  %coefs.load = load float* %coefs.addr, align 4, !dbg !98 ; [#uses=2 type=float] [debug line = 27:5]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %coefs.load) nounwind
  %iir.addr = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 2, i32 %i, i32 %j, !dbg !98 ; [#uses=1 type=float*] [debug line = 27:5]
  store float %coefs.load, float* %iir.addr, align 4, !dbg !98 ; [debug line = 27:5]
  %rend = call i32 (...)* @_ssdm_op_SpecRegionEnd(i8* getelementptr inbounds ([15 x i8]* @.str3, i32 0, i32 0), i32 %rbegin) nounwind, !dbg !99 ; [#uses=0 type=i32] [debug line = 28:4]
  %j.1 = add nsw i32 %j, 1, !dbg !100             ; [#uses=1 type=i32] [debug line = 26:40]
  call void @llvm.dbg.value(metadata !{i32 %j.1}, i64 0, metadata !101), !dbg !100 ; [debug line = 26:40] [debug variable = j]
  br label %.preheader, !dbg !100                 ; [debug line = 26:40]

; <label>:3                                       ; preds = %.preheader
  %i.1 = add nsw i32 %i, 1, !dbg !102             ; [#uses=1 type=i32] [debug line = 25:28]
  call void @llvm.dbg.value(metadata !{i32 %i.1}, i64 0, metadata !103), !dbg !102 ; [debug line = 25:28] [debug variable = i]
  br label %1, !dbg !102                          ; [debug line = 25:28]

; <label>:4                                       ; preds = %1
  ret void, !dbg !104                             ; [debug line = 30:2]
}

; [#uses=1]
define internal fastcc float @"IIRFilter::filter"(float %input) nounwind align 2 {
  call void @llvm.dbg.value(metadata !{float %input}, i64 0, metadata !105), !dbg !106 ; [debug line = 31:23] [debug variable = input]
  call void @llvm.dbg.value(metadata !{float %input}, i64 0, metadata !107), !dbg !109 ; [debug line = 32:47] [debug variable = temp]
  br label %1, !dbg !110                          ; [debug line = 34:26]

; <label>:1                                       ; preds = %2, %0
  %temp = phi float [ %input, %0 ], [ %acc, %2 ]  ; [#uses=4 type=float]
  %i = phi i32 [ 0, %0 ], [ %i.2, %2 ]            ; [#uses=13 type=i32]
  %exitcond = icmp eq i32 %i, 5, !dbg !110        ; [#uses=1 type=i1] [debug line = 34:26]
  br i1 %exitcond, label %3, label %2, !dbg !110  ; [debug line = 34:26]

; <label>:2                                       ; preds = %1
  call void (...)* @_ssdm_op_SpecLoopName(i8* getelementptr inbounds ([12 x i8]* @.str4, i32 0, i32 0)) nounwind, !dbg !112 ; [debug line = 34:45]
  %rbegin = call i32 (...)* @_ssdm_op_SpecRegionBegin(i8* getelementptr inbounds ([12 x i8]* @.str4, i32 0, i32 0)) nounwind, !dbg !112 ; [#uses=1 type=i32] [debug line = 34:45]
  %iir.addr = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 2, i32 %i, i32 0, !dbg !114 ; [#uses=1 type=float*] [debug line = 36:4]
  %b0 = load float* %iir.addr, align 4, !dbg !114 ; [#uses=2 type=float] [debug line = 36:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %b0) nounwind
  call void @llvm.dbg.value(metadata !{float %b0}, i64 0, metadata !115), !dbg !114 ; [debug line = 36:4] [debug variable = b0]
  %iir.addr.1 = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 2, i32 %i, i32 1, !dbg !116 ; [#uses=1 type=float*] [debug line = 37:4]
  %b1 = load float* %iir.addr.1, align 4, !dbg !116 ; [#uses=2 type=float] [debug line = 37:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %b1) nounwind
  call void @llvm.dbg.value(metadata !{float %b1}, i64 0, metadata !117), !dbg !116 ; [debug line = 37:4] [debug variable = b1]
  %iir.addr.2 = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 2, i32 %i, i32 2, !dbg !118 ; [#uses=1 type=float*] [debug line = 38:4]
  %b2 = load float* %iir.addr.2, align 4, !dbg !118 ; [#uses=2 type=float] [debug line = 38:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %b2) nounwind
  call void @llvm.dbg.value(metadata !{float %b2}, i64 0, metadata !119), !dbg !118 ; [debug line = 38:4] [debug variable = b2]
  %iir.addr.3 = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 2, i32 %i, i32 4, !dbg !120 ; [#uses=1 type=float*] [debug line = 39:4]
  %a1 = load float* %iir.addr.3, align 4, !dbg !120 ; [#uses=2 type=float] [debug line = 39:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %a1) nounwind
  call void @llvm.dbg.value(metadata !{float %a1}, i64 0, metadata !121), !dbg !120 ; [debug line = 39:4] [debug variable = a1]
  %iir.addr.4 = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 2, i32 %i, i32 5, !dbg !122 ; [#uses=1 type=float*] [debug line = 40:4]
  %a2 = load float* %iir.addr.4, align 4, !dbg !122 ; [#uses=2 type=float] [debug line = 40:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %a2) nounwind
  call void @llvm.dbg.value(metadata !{float %a2}, i64 0, metadata !123), !dbg !122 ; [debug line = 40:4] [debug variable = a2]
  %iir.addr.5 = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 0, i32 %i, i32 1, !dbg !124 ; [#uses=2 type=float*] [debug line = 42:4]
  %iir.load = load float* %iir.addr.5, align 4, !dbg !124 ; [#uses=4 type=float] [debug line = 42:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %iir.load) nounwind
  %iir.addr.6 = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 0, i32 %i, i32 2, !dbg !124 ; [#uses=1 type=float*] [debug line = 42:4]
  store float %iir.load, float* %iir.addr.6, align 4, !dbg !124 ; [debug line = 42:4]
  %iir.addr.7 = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 0, i32 %i, i32 0, !dbg !125 ; [#uses=2 type=float*] [debug line = 43:4]
  %iir.load.1 = load float* %iir.addr.7, align 4, !dbg !125 ; [#uses=4 type=float] [debug line = 43:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %iir.load.1) nounwind
  store float %iir.load.1, float* %iir.addr.5, align 4, !dbg !125 ; [debug line = 43:4]
  store float %temp, float* %iir.addr.7, align 4, !dbg !126 ; [debug line = 44:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %temp) nounwind
  %tmp = fmul float %b0, %temp, !dbg !127         ; [#uses=1 type=float] [debug line = 46:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %iir.load.1) nounwind
  %tmp.3 = fmul float %b1, %iir.load.1, !dbg !127 ; [#uses=1 type=float] [debug line = 46:4]
  %tmp.4 = fadd float %tmp, %tmp.3, !dbg !127     ; [#uses=1 type=float] [debug line = 46:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %iir.load) nounwind
  %tmp.5 = fmul float %b2, %iir.load, !dbg !127   ; [#uses=1 type=float] [debug line = 46:4]
  %tmp.6 = fadd float %tmp.4, %tmp.5, !dbg !127   ; [#uses=1 type=float] [debug line = 46:4]
  %iir.addr.8 = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 1, i32 %i, i32 1, !dbg !127 ; [#uses=2 type=float*] [debug line = 46:4]
  %iir.load.2 = load float* %iir.addr.8, align 4, !dbg !127 ; [#uses=4 type=float] [debug line = 46:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %iir.load.2) nounwind
  %tmp.7 = fmul float %a1, %iir.load.2, !dbg !127 ; [#uses=1 type=float] [debug line = 46:4]
  %tmp.8 = fsub float %tmp.6, %tmp.7, !dbg !127   ; [#uses=1 type=float] [debug line = 46:4]
  %iir.addr.9 = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 1, i32 %i, i32 2, !dbg !127 ; [#uses=2 type=float*] [debug line = 46:4]
  %iir.load.3 = load float* %iir.addr.9, align 4, !dbg !127 ; [#uses=2 type=float] [debug line = 46:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %iir.load.3) nounwind
  %tmp.9 = fmul float %a2, %iir.load.3, !dbg !127 ; [#uses=1 type=float] [debug line = 46:4]
  %acc = fsub float %tmp.8, %tmp.9, !dbg !127     ; [#uses=5 type=float] [debug line = 46:4]
  call void @llvm.dbg.value(metadata !{float %acc}, i64 0, metadata !128), !dbg !127 ; [debug line = 46:4] [debug variable = acc]
  %iir.addr.10 = getelementptr inbounds %class.IIRFilter.0* @iir, i32 0, i32 1, i32 %i, i32 0, !dbg !129 ; [#uses=1 type=float*] [debug line = 47:4]
  store float %acc, float* %iir.addr.10, align 4, !dbg !129 ; [debug line = 47:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %iir.load.2) nounwind
  store float %iir.load.2, float* %iir.addr.9, align 4, !dbg !130 ; [debug line = 50:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %acc) nounwind
  store float %acc, float* %iir.addr.8, align 4, !dbg !131 ; [debug line = 51:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(float %acc) nounwind
  call void @llvm.dbg.value(metadata !{float %acc}, i64 0, metadata !107), !dbg !132 ; [debug line = 52:4] [debug variable = temp]
  %rend = call i32 (...)* @_ssdm_op_SpecRegionEnd(i8* getelementptr inbounds ([12 x i8]* @.str4, i32 0, i32 0), i32 %rbegin) nounwind, !dbg !133 ; [#uses=0 type=i32] [debug line = 53:3]
  %i.2 = add nsw i32 %i, 1, !dbg !134             ; [#uses=1 type=i32] [debug line = 34:40]
  call void @llvm.dbg.value(metadata !{i32 %i.2}, i64 0, metadata !135), !dbg !134 ; [debug line = 34:40] [debug variable = i]
  br label %1, !dbg !134                          ; [debug line = 34:40]

; <label>:3                                       ; preds = %1
  %temp.0.lcssa = phi float [ %temp, %1 ]         ; [#uses=1 type=float]
  ret float %temp.0.lcssa, !dbg !136              ; [debug line = 54:3]
}

!llvm.dbg.cu = !{!0}
!opencl.kernels = !{!48, !55, !61, !65, !65}
!hls.encrypted.func = !{}

!0 = metadata !{i32 786449, i32 0, i32 4, metadata !"C:/Users/marti/Documents/EmbeddedSystems/project/equalizer/equalizer/.autopilot/db/iir.pragma.2.cpp", metadata !"C:\5CUsers\5Cmarti\5CDocuments\5CEmbeddedSystems\5Cproject", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !3, metadata !45} ; [ DW_TAG_compile_unit ]
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !5, metadata !19, metadata !42, metadata !43, metadata !44}
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"equalizer", metadata !"equalizer", metadata !"_Z9equalizerPffiPA6_f", metadata !6, i32 3, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, void (float*, float, i32, [6 x float]*)* @equalizer, null, null, metadata !17, i32 3} ; [ DW_TAG_subprogram ]
!6 = metadata !{i32 786473, metadata !"equalizer/iir.cpp", metadata !"C:\5CUsers\5Cmarti\5CDocuments\5CEmbeddedSystems\5Cproject", null} ; [ DW_TAG_file_type ]
!7 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !8, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!8 = metadata !{null, metadata !9, metadata !10, metadata !12, metadata !13}
!9 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !10} ; [ DW_TAG_pointer_type ]
!10 = metadata !{i32 786454, null, metadata !"data_t", metadata !6, i32 2, i64 0, i64 0, i64 0, i32 0, metadata !11} ; [ DW_TAG_typedef ]
!11 = metadata !{i32 786468, null, metadata !"float", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 4} ; [ DW_TAG_base_type ]
!12 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!13 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !14} ; [ DW_TAG_pointer_type ]
!14 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 192, i64 32, i32 0, i32 0, metadata !10, metadata !15, i32 0, i32 0} ; [ DW_TAG_array_type ]
!15 = metadata !{metadata !16}
!16 = metadata !{i32 786465, i64 0, i64 5}        ; [ DW_TAG_subrange_type ]
!17 = metadata !{metadata !18}
!18 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!19 = metadata !{i32 786478, i32 0, null, metadata !"setCoeffs", metadata !"setCoeffs", metadata !"_ZN9IIRFilter9setCoeffsEPA6_f", metadata !20, i32 24, metadata !21, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, metadata !38, metadata !17, i32 24} ; [ DW_TAG_subprogram ]
!20 = metadata !{i32 786473, metadata !"equalizer/iir.h", metadata !"C:\5CUsers\5Cmarti\5CDocuments\5CEmbeddedSystems\5Cproject", null} ; [ DW_TAG_file_type ]
!21 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !22, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!22 = metadata !{null, metadata !23, metadata !13}
!23 = metadata !{i32 786447, i32 0, metadata !"", i32 0, i32 0, i64 32, i64 32, i64 0, i32 64, metadata !24} ; [ DW_TAG_pointer_type ]
!24 = metadata !{i32 786434, null, metadata !"IIRFilter", metadata !20, i32 8, i64 1920, i64 32, i32 0, i32 0, null, metadata !25, i32 0, null, null} ; [ DW_TAG_class_type ]
!25 = metadata !{metadata !26, metadata !31, metadata !32, metadata !35, metadata !38, metadata !39}
!26 = metadata !{i32 786445, metadata !24, metadata !"x", metadata !20, i32 10, i64 480, i64 32, i64 0, i32 0, metadata !27} ; [ DW_TAG_member ]
!27 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 480, i64 32, i32 0, i32 0, metadata !10, metadata !28, i32 0, i32 0} ; [ DW_TAG_array_type ]
!28 = metadata !{metadata !29, metadata !30}
!29 = metadata !{i32 786465, i64 0, i64 4}        ; [ DW_TAG_subrange_type ]
!30 = metadata !{i32 786465, i64 0, i64 2}        ; [ DW_TAG_subrange_type ]
!31 = metadata !{i32 786445, metadata !24, metadata !"y", metadata !20, i32 11, i64 480, i64 32, i64 480, i32 0, metadata !27} ; [ DW_TAG_member ]
!32 = metadata !{i32 786445, metadata !24, metadata !"coeff_array", metadata !20, i32 12, i64 960, i64 32, i64 960, i32 0, metadata !33} ; [ DW_TAG_member ]
!33 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 960, i64 32, i32 0, i32 0, metadata !10, metadata !34, i32 0, i32 0} ; [ DW_TAG_array_type ]
!34 = metadata !{metadata !29, metadata !16}
!35 = metadata !{i32 786478, i32 0, metadata !24, metadata !"IIRFilter", metadata !"IIRFilter", metadata !"", metadata !20, i32 13, metadata !36, i1 false, i1 false, i32 0, i32 0, null, i32 256, i1 false, null, null, i32 0, metadata !17, i32 13} ; [ DW_TAG_subprogram ]
!36 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !37, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!37 = metadata !{null, metadata !23}
!38 = metadata !{i32 786478, i32 0, metadata !24, metadata !"setCoeffs", metadata !"setCoeffs", metadata !"_ZN9IIRFilter9setCoeffsEPA6_f", metadata !20, i32 24, metadata !21, i1 false, i1 false, i32 0, i32 0, null, i32 256, i1 false, null, null, i32 0, metadata !17, i32 24} ; [ DW_TAG_subprogram ]
!39 = metadata !{i32 786478, i32 0, metadata !24, metadata !"filter", metadata !"filter", metadata !"_ZN9IIRFilter6filterEf", metadata !20, i32 31, metadata !40, i1 false, i1 false, i32 0, i32 0, null, i32 256, i1 false, null, null, i32 0, metadata !17, i32 31} ; [ DW_TAG_subprogram ]
!40 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !41, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!41 = metadata !{metadata !10, metadata !23, metadata !10}
!42 = metadata !{i32 786478, i32 0, null, metadata !"filter", metadata !"filter", metadata !"_ZN9IIRFilter6filterEf", metadata !20, i32 31, metadata !40, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, metadata !39, metadata !17, i32 31} ; [ DW_TAG_subprogram ]
!43 = metadata !{i32 786478, i32 0, null, metadata !"IIRFilter", metadata !"IIRFilter", metadata !"_ZN9IIRFilterC1Ev", metadata !20, i32 13, metadata !36, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, metadata !35, metadata !17, i32 13} ; [ DW_TAG_subprogram ]
!44 = metadata !{i32 786478, i32 0, null, metadata !"IIRFilter", metadata !"IIRFilter", metadata !"_ZN9IIRFilterC2Ev", metadata !20, i32 13, metadata !36, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, metadata !35, metadata !17, i32 13} ; [ DW_TAG_subprogram ]
!45 = metadata !{metadata !46}
!46 = metadata !{metadata !47}
!47 = metadata !{i32 786484, i32 0, metadata !5, metadata !"iir", metadata !"iir", metadata !"", metadata !6, i32 4, metadata !24, i32 1, i32 1, %class.IIRFilter.0* @iir} ; [ DW_TAG_variable ]
!48 = metadata !{void (float*, float, i32, [6 x float]*)* @equalizer, metadata !49, metadata !50, metadata !51, metadata !52, metadata !53, metadata !54}
!49 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 0, i32 0, i32 1}
!50 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none", metadata !"none"}
!51 = metadata !{metadata !"kernel_arg_type", metadata !"data_t*", metadata !"data_t", metadata !"int", metadata !"data_t [6]*"}
!52 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !"", metadata !""}
!53 = metadata !{metadata !"kernel_arg_name", metadata !"y", metadata !"x", metadata !"mode", metadata !"coeffs"}
!54 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!55 = metadata !{null, metadata !56, metadata !57, metadata !58, metadata !59, metadata !60, metadata !54}
!56 = metadata !{metadata !"kernel_arg_addr_space", i32 1}
!57 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none"}
!58 = metadata !{metadata !"kernel_arg_type", metadata !"data_t [6]*"}
!59 = metadata !{metadata !"kernel_arg_type_qual", metadata !""}
!60 = metadata !{metadata !"kernel_arg_name", metadata !"coefs"}
!61 = metadata !{null, metadata !62, metadata !57, metadata !63, metadata !59, metadata !64, metadata !54}
!62 = metadata !{metadata !"kernel_arg_addr_space", i32 0}
!63 = metadata !{metadata !"kernel_arg_type", metadata !"data_t"}
!64 = metadata !{metadata !"kernel_arg_name", metadata !"input"}
!65 = metadata !{null, metadata !66, metadata !67, metadata !68, metadata !69, metadata !70, metadata !54}
!66 = metadata !{metadata !"kernel_arg_addr_space"}
!67 = metadata !{metadata !"kernel_arg_access_qual"}
!68 = metadata !{metadata !"kernel_arg_type"}
!69 = metadata !{metadata !"kernel_arg_type_qual"}
!70 = metadata !{metadata !"kernel_arg_name"}
!71 = metadata !{i32 786689, metadata !5, metadata !"y", metadata !6, i32 16777219, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!72 = metadata !{i32 3, i32 24, metadata !5, null}
!73 = metadata !{i32 786689, metadata !5, metadata !"x", metadata !6, i32 33554435, metadata !10, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!74 = metadata !{i32 3, i32 34, metadata !5, null}
!75 = metadata !{i32 786689, metadata !5, metadata !"mode", metadata !6, i32 50331651, metadata !12, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!76 = metadata !{i32 3, i32 41, metadata !5, null}
!77 = metadata !{i32 786689, metadata !5, metadata !"coeffs", metadata !6, i32 67108867, metadata !13, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!78 = metadata !{i32 3, i32 54, metadata !5, null}
!79 = metadata !{i32 3, i32 75, metadata !80, null}
!80 = metadata !{i32 786443, metadata !5, i32 3, i32 74, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!81 = metadata !{i32 4, i32 1, metadata !80, null}
!82 = metadata !{i32 5, i32 3, metadata !80, null}
!83 = metadata !{i32 6, i32 9, metadata !80, null}
!84 = metadata !{i32 8, i32 4, metadata !85, null}
!85 = metadata !{i32 786443, metadata !80, i32 7, i32 8, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!86 = metadata !{i32 10, i32 1, metadata !80, null}
!87 = metadata !{i32 786689, metadata !19, metadata !"coefs", metadata !20, i32 33554456, metadata !13, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!88 = metadata !{i32 24, i32 24, metadata !19, null}
!89 = metadata !{i32 24, i32 44, metadata !90, null}
!90 = metadata !{i32 786443, metadata !19, i32 24, i32 43, metadata !20, i32 2} ; [ DW_TAG_lexical_block ]
!91 = metadata !{i32 25, i32 14, metadata !92, null}
!92 = metadata !{i32 786443, metadata !90, i32 25, i32 3, metadata !20, i32 3} ; [ DW_TAG_lexical_block ]
!93 = metadata !{i32 26, i32 31, metadata !94, null}
!94 = metadata !{i32 786443, metadata !95, i32 26, i32 19, metadata !20, i32 5} ; [ DW_TAG_lexical_block ]
!95 = metadata !{i32 786443, metadata !92, i32 25, i32 33, metadata !20, i32 4} ; [ DW_TAG_lexical_block ]
!96 = metadata !{i32 26, i32 46, metadata !97, null}
!97 = metadata !{i32 786443, metadata !94, i32 26, i32 45, metadata !20, i32 6} ; [ DW_TAG_lexical_block ]
!98 = metadata !{i32 27, i32 5, metadata !97, null}
!99 = metadata !{i32 28, i32 4, metadata !97, null}
!100 = metadata !{i32 26, i32 40, metadata !94, null}
!101 = metadata !{i32 786688, metadata !94, metadata !"j", metadata !20, i32 26, metadata !12, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!102 = metadata !{i32 25, i32 28, metadata !92, null}
!103 = metadata !{i32 786688, metadata !92, metadata !"i", metadata !20, i32 25, metadata !12, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!104 = metadata !{i32 30, i32 2, metadata !90, null}
!105 = metadata !{i32 786689, metadata !42, metadata !"input", metadata !20, i32 33554463, metadata !10, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!106 = metadata !{i32 31, i32 23, metadata !42, null}
!107 = metadata !{i32 786688, metadata !108, metadata !"temp", metadata !20, i32 32, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!108 = metadata !{i32 786443, metadata !42, i32 31, i32 30, metadata !20, i32 7} ; [ DW_TAG_lexical_block ]
!109 = metadata !{i32 32, i32 47, metadata !108, null}
!110 = metadata !{i32 34, i32 26, metadata !111, null}
!111 = metadata !{i32 786443, metadata !108, i32 34, i32 15, metadata !20, i32 8} ; [ DW_TAG_lexical_block ]
!112 = metadata !{i32 34, i32 45, metadata !113, null}
!113 = metadata !{i32 786443, metadata !111, i32 34, i32 44, metadata !20, i32 9} ; [ DW_TAG_lexical_block ]
!114 = metadata !{i32 36, i32 4, metadata !113, null}
!115 = metadata !{i32 786688, metadata !108, metadata !"b0", metadata !20, i32 32, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!116 = metadata !{i32 37, i32 4, metadata !113, null}
!117 = metadata !{i32 786688, metadata !108, metadata !"b1", metadata !20, i32 32, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!118 = metadata !{i32 38, i32 4, metadata !113, null}
!119 = metadata !{i32 786688, metadata !108, metadata !"b2", metadata !20, i32 32, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!120 = metadata !{i32 39, i32 4, metadata !113, null}
!121 = metadata !{i32 786688, metadata !108, metadata !"a1", metadata !20, i32 32, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!122 = metadata !{i32 40, i32 4, metadata !113, null}
!123 = metadata !{i32 786688, metadata !108, metadata !"a2", metadata !20, i32 32, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!124 = metadata !{i32 42, i32 4, metadata !113, null}
!125 = metadata !{i32 43, i32 4, metadata !113, null}
!126 = metadata !{i32 44, i32 4, metadata !113, null}
!127 = metadata !{i32 46, i32 4, metadata !113, null}
!128 = metadata !{i32 786688, metadata !108, metadata !"acc", metadata !20, i32 32, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!129 = metadata !{i32 47, i32 4, metadata !113, null}
!130 = metadata !{i32 50, i32 4, metadata !113, null}
!131 = metadata !{i32 51, i32 4, metadata !113, null}
!132 = metadata !{i32 52, i32 4, metadata !113, null}
!133 = metadata !{i32 53, i32 3, metadata !113, null}
!134 = metadata !{i32 34, i32 40, metadata !111, null}
!135 = metadata !{i32 786688, metadata !111, metadata !"i", metadata !20, i32 34, metadata !12, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!136 = metadata !{i32 54, i32 3, metadata !108, null}
