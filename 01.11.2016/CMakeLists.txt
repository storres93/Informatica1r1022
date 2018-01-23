cmake_minimum_required(VERSION 3.8)
project(OpenCV)

set(CMAKE_C_STANDARD 99)

set(OPEN_CAMERA_SOURCE_FILES AbrirCamara/main1.c)
set(CREATE_BUTTON_SOURCE_FILES CrearBoton/main.c)
set(CREATE_TEXT_INPUT_SOURCE_FILES CrearCampoDeTexto/main.c)
set(BORDER_DETECTION_SOURCE_FILES DeteccionBordes/main.c)
set(EYE_DETECTION_SOURCE_FILES DeteccionOjos/Pruebas.cpp)
set(SHOW_IMAGE_SOURCE_FILES MostrarImagen/main.c)

add_executable(openCamera ${OPEN_CAMERA_SOURCE_FILES})
add_executable(createButton ${CREATE_BUTTON_SOURCE_FILES})
add_executable(createTextInput ${CREATE_TEXT_INPUT_SOURCE_FILES})
add_executable(eyeDetection ${EYE_DETECTION_SOURCE_FILES})
add_executable(borderDetection ${BORDER_DETECTION_SOURCE_FILES})
add_executable(showImage ${SHOW_IMAGE_SOURCE_FILES})

INCLUDE_DIRECTORIES(/usr/local/Cellar/opencv/2.4.13.2/include)
LINK_DIRECTORIES(/usr/local/Cellar/opencv/2.4.13.2/lib)

file(GLOB LIBRARIES "/usr/local/Cellar/opencv/2.4.13.2/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(openCamera  ${LIBRARIES})
TARGET_LINK_LIBRARIES(createButton  ${LIBRARIES})
TARGET_LINK_LIBRARIES(createTextInput  ${LIBRARIES})
TARGET_LINK_LIBRARIES(borderDetection  ${LIBRARIES})
TARGET_LINK_LIBRARIES(eyeDetection  ${LIBRARIES})
TARGET_LINK_LIBRARIES(showImage  ${LIBRARIES})