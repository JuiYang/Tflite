#ifndef NATIVEINTERPRETERWRAPPER_JNI_H_
#define NATIVEINTERPRETERWRAPPER_JNI_H_

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <stdarg.h>
#include <stdlib.h>
#include <memory>
#include "/home/tclxa/TfLite/model.h"
#include "/home/tclxa/TfLite/exception_jni.h"
#include "/home/tclxa/TfLite/context.h"
#include "/home/tclxa/TfLite/error_reporter.h"
#include "/home/tclxa/TfLite/interpreter.h"
#include "/home/tclxa/TfLite/register.h"
// #include "tensorflow/contrib/lite/java/src/main/native/tensor_jni.h"

using namespace std;

namespace tflite{

  // extern std::unique_ptr<OpResolver> CreateOpResolver();
  std::unique_ptr<OpResolver> CreateOpResolver() {  // NOLINT
    return std::unique_ptr<tflite::ops::builtin::BuiltinOpResolver>(
      new tflite::ops::builtin::BuiltinOpResolver());
  }

} // namespace

/**LiYu*/
// Verifies whether the model is a flatbuffer file.
class JNIFlatBufferVerifier: public tflite::TfLiteVerifier {
 public:
  bool Verify(const char* data, int length,
    tflite::ErrorReporter* reporter)
    override {
   if (!VerifyModel(data, length)) {
     reporter->Report("The model is not a valid Flatbuffer file");
     return false;
   }
    cout << "nativeinterpreterwrapper_jni.h Verifier ..." << endl;
    return true;
  }

  // TODO(yichengfan): evaluate the benefit to use tflite verifier.
  bool VerifyModel(const void* buf, size_t len){
  flatbuffers::Verifier verifier(static_cast<const uint8_t*>(buf), len);
  return tflite::VerifyModelBuffer(verifier);
}

  ~JNIFlatBufferVerifier(){}
};

/** LiYu*/
BufferErrorReporter* createErrorReporter() {
  string errorInfo = "BufferErrorReporter class exception ";
  // buffer->outInfo();
  BufferErrorReporter* error_reporter = new BufferErrorReporter(errorInfo);
  // BufferErrorReporter* error_reporter = buffer;
  cout << "createErrorReporter function" << endl;
  return error_reporter;
}


/*LiYu*/
std::unique_ptr<tflite::FlatBufferModel> createModel(BufferErrorReporter* error_reporter,
  string model_file){ 
  if (error_reporter == nullptr){
    cout << "error_reporter nullptr" << endl;
    return 0;
  }
  const char* path = const_cast<char*>(model_file.c_str());
  std::unique_ptr<tflite::TfLiteVerifier> verifier;
  verifier.reset(new JNIFlatBufferVerifier());
  tflite::FlatBufferModel* flatBuffer;
  auto model = flatBuffer->VerifyAndBuildFromFile(path,verifier.get(),error_reporter);

  if (!model) {
    cout << "create model faild" << endl;
    return 0;
  }
  cout << "createModel over ... " << endl;
  return model;
}

/*LiYu*/
std::unique_ptr<tflite::Interpreter> createInterpreter(string model_file, 
  int num_threads) {
  // tflite::FlatBufferModel *model = dynamic_cast<tflite::FlatBufferModel *>(bufferModel.get());
  // tflite::FlatBufferModel *model = dynamic_cast<tflite::FlatBufferModel *>(bufferModel.release());
 
  BufferErrorReporter* error_reporter = createErrorReporter();
  if (error_reporter == nullptr) return 0;
  std::unique_ptr<tflite::FlatBufferModel> model = createModel(error_reporter, model_file);
  if (model == nullptr) return 0;
  auto resolver = ::tflite::CreateOpResolver();
  // std::unique_ptr<tflite::Interpreter> interpreter;
  // TfLiteStatus status = tflite::InterpreterBuilder(*model, *(resolver.get()))(
  //     &interpreter, static_cast<int>(num_threads));
  // if (status != kTfLiteOk) {
  //   throwException(env, kIllegalArgumentException,
  //                  "Internal error: Cannot create interpreter: %s",
  //                  error_reporter->CachedErrorMessage());
  //   return 0;
  // }
  // // allocates memory
  // status = interpreter->AllocateTensors();
  // if (status != kTfLiteOk) {
  //   throwException(
  //       env, kIllegalStateException,
  //       "Internal error: Unexpected failure when preparing tensor allocations:"
  //       " %s",
  //       error_reporter->CachedErrorMessage());
  //   return 0;
  // }
  // return interpreter;
  cout << "create interpreter ..." << endl;
  return NULL;
}

#endif /* NATIVEINTERPRETERWRAPPER_JNI_H_ */
