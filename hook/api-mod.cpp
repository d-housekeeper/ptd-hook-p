#include "android-utils.h"
#include "frida-gum.h"
#include "helpers.h"
#include "il2cpp-appdata.h"
#include "response-loader.h"
#include <android/log.h>

using namespace app;

static bool replacement_EnvironmentData_get_CurrentIsAesEncrypt(EnvironmentData *__this, MethodInfo *method) {
  // __android_log_print(ANDROID_LOG_DEBUG, androidLogTag, "EnvironmentData_get_CurrentIsAesEncrypt");
  return false;
}

static void replacement_EnvironmentData_set_IsGZipCompress(EnvironmentData *__this, bool value, MethodInfo *method) {
  // __android_log_print(ANDROID_LOG_DEBUG, androidLogTag, "EnvironmentData_set_IsGZipCompress");
  __this->_IsGZipCompress_k__BackingField = false;
}

static bool replacement_UnityWebRequest_get_isDone(UnityWebRequest *__this, MethodInfo *method) {
  // __android_log_print(ANDROID_LOG_DEBUG, androidLogTag, "UnityWebRequest_get_isDone");
  return true;
}

static UnityWebRequestAsyncOperation *replacement_UnityWebRequest_SendWebRequest(UnityWebRequest *__this,
                                                                                 MethodInfo *method) {
  // __android_log_print(ANDROID_LOG_DEBUG, androidLogTag, "UnityWebRequest_SendWebRequest");
  return nullptr;
}

static String *replacement_DownloadHandler_GetText(DownloadHandler *__this, MethodInfo *method) {
  // __android_log_print(ANDROID_LOG_DEBUG, androidLogTag, "DownloadHandler_GetText");
  return (String *)il2cpp_string_new("a");
}

static String *replacement_UnityWebRequest_get_error(UnityWebRequest *__this, MethodInfo *method) {
  // __android_log_print(ANDROID_LOG_DEBUG, androidLogTag, "UnityWebRequest_get_error");
  return nullptr;
}

static RequestBase_ResponseParameter *replacement_RequestBase_DecodeResultData(RequestBase *__this, String *receiveData,
                                                                               MethodInfo *method) {
  std::string apiName = il2cppi_to_string(__this->_ApiName_k__BackingField);
  __android_log_print(ANDROID_LOG_INFO, androidLogTag, "RequestBase_DecodeResultData: %s", apiName.c_str());

  MethodInfo *tryGetValueMethod = (MethodInfo *)__this->_RequestPostParameter->klass->vtable.TryGetValue.method;
  String *pmKey = (String *)il2cpp_string_new("pm");
  String *pmValue = nullptr;
  std::string stdPmValue;
  bool tryGetValueSuccess = Dictionary_2_System_String_System_Object__TryGetValue(
      __this->_RequestPostParameter, pmKey, (Object **)&pmValue, tryGetValueMethod);
  if (tryGetValueSuccess) {
    stdPmValue = il2cppi_to_string(pmValue);
  } else {
    __android_log_print(ANDROID_LOG_ERROR, androidLogTag, "Failed to get Request PM value from map");
  }

  std::string response = loadResponse(apiName, stdPmValue);
  String *replacementReceiveData = (String *)il2cpp_string_new(response.c_str());
  RequestBase_ResponseParameter *ret = RequestBase_DecodeResultData(__this, replacementReceiveData, method);

  return ret;
}

static bool replacement_ReLoginUtility_CheckMustReLogin(MethodInfo *method) {
  __android_log_print(ANDROID_LOG_INFO, androidLogTag, "ReLoginUtility_CheckMustReLogin");
  return false;
}

static void
replacement_ScenePrefabEventTopVote_WindowUI_VotePointUI_SetText(ScenePrefabEventTopVote_WindowUI_VotePointUI *__this,
                                                                 ScenePrefabEventTopVote_WindowUI_Param *param,
                                                                 MethodInfo *method) {
  __android_log_print(ANDROID_LOG_INFO, androidLogTag, "ScenePrefabEventTopVote_WindowUI_VotePointUI_SetText");
}

static bool replacement_SceneEventTopBase_InitTradeList_d_67_MoveNext(SceneEventTopBase_InitTradeList_d_67 *__this,
                                                                      MethodInfo *method) {
  __android_log_print(ANDROID_LOG_INFO, androidLogTag, "SceneEventTopBase_InitTradeList_d_67_MoveNext");
  __this->__4__this->_IsStartCoroutine = false;
  return false;
}

void initApiMod() {
  GumInterceptor *interceptor = gum_interceptor_obtain();

  gum_interceptor_begin_transaction(interceptor);
  gum_interceptor_replace(interceptor, GSIZE_TO_POINTER(EnvironmentData_get_CurrentIsAesEncrypt),
                          (void *)replacement_EnvironmentData_get_CurrentIsAesEncrypt, nullptr);
  gum_interceptor_replace(interceptor, GSIZE_TO_POINTER(EnvironmentData_set_IsGZipCompress),
                          (void *)replacement_EnvironmentData_set_IsGZipCompress, nullptr);
  gum_interceptor_replace(interceptor, GSIZE_TO_POINTER(UnityWebRequest_get_isDone),
                          (void *)replacement_UnityWebRequest_get_isDone, nullptr);
  gum_interceptor_replace(interceptor, GSIZE_TO_POINTER(UnityWebRequest_SendWebRequest),
                          (void *)replacement_UnityWebRequest_SendWebRequest, nullptr);
  gum_interceptor_replace(interceptor, GSIZE_TO_POINTER(UnityWebRequest_get_error),
                          (void *)replacement_UnityWebRequest_get_error, nullptr);
  gum_interceptor_replace(interceptor, GSIZE_TO_POINTER(DownloadHandler_GetText),
                          (void *)replacement_DownloadHandler_GetText, nullptr);
  gum_interceptor_replace(interceptor, GSIZE_TO_POINTER(RequestBase_DecodeResultData),
                          (void *)replacement_RequestBase_DecodeResultData, nullptr);
  gum_interceptor_replace(interceptor, GSIZE_TO_POINTER(ReLoginUtility_CheckMustReLogin),
                          (void *)replacement_ReLoginUtility_CheckMustReLogin, nullptr);
  gum_interceptor_replace(interceptor, GSIZE_TO_POINTER(ScenePrefabEventTopVote_WindowUI_VotePointUI_SetText),
                          (void *)replacement_ScenePrefabEventTopVote_WindowUI_VotePointUI_SetText, nullptr);
  gum_interceptor_replace(interceptor, GSIZE_TO_POINTER(SceneEventTopBase_InitTradeList_d_67_MoveNext),
                          (void *)replacement_SceneEventTopBase_InitTradeList_d_67_MoveNext, nullptr);
  gum_interceptor_end_transaction(interceptor);
}
