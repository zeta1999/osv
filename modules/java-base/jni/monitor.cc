#include <jni.h>
#include "monitor.hh"
#include "../balloon/jvm_balloon.hh"

/*
 * Class:     io_osv_OSvGCMonitor
 * Method:    NotifyOSv
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_io_osv_OSvGCMonitor_NotifyOSv(JNIEnv *env, jclass mon, jlong handle, jlong qty)
{
    jvm_balloon_shrinker *shrinker = (jvm_balloon_shrinker *)handle;
    shrinker->release_memory((qty / memory::balloon_size) + !!(qty % memory::balloon_size));
}
