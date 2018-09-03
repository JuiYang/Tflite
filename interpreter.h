/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
// Main abstraction controlling the tflite interpreter.
// See context.h for the API for defining operations (TfLiteRegistration).
#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include <iostream>
#include <complex>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>

#include "/home/tclxa/TfLite/allocation.h"
#include "/home/tclxa/TfLite/context.h"
#include "/home/tclxa/TfLite/error_reporter.h"
// #include "tensorflow/contrib/lite/memory_planner.h"
// #include "tensorflow/contrib/lite/profiling/profiler.h"

namespace tflite {

class Interpreter {
 public:

 private:

};

}  // namespace tflite
#endif  // INTERPRETER_H_
