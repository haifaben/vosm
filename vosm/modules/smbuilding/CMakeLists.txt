include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../utils/include" "${CMAKE_CURRENT_SOURCE_DIR}/../cvcommon/include"
"${CMAKE_CURRENT_SOURCE_DIR}/../ensembletraining/include" "${CMAKE_CURRENT_SOURCE_DIR}/../integraltransform/include"
"${CMAKE_CURRENT_SOURCE_DIR}/../featureextraction/include")
set(deps opencv_core opencv_imgproc opencv_highgui)
define_vosm_module(smbuilding vosm_utils vosm_cvcommon vosm_featureextraction vosm_integraltransform ${deps})
