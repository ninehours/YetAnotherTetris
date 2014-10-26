#include "cocos2d.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include "test.h"
#include "JniTest.h"

#define CLASS_NAME "com/DialogBox/org/JniTestHelper"

using namespace cocos2d;

extern "C"
{
	void showTipDialog(const char *title, const char *msg)
	{
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, CLASS_NAME, "showTipDialog", "(Ljava/lang/String;Ljava/lang/String;)V"))
		{
			jstring jTitle = t.env->NewStringUTF(title);
			jstring jMsg = t.env->NewStringUTF(msg);
			t.env->CallStaticVoidMethod(t.classID, t.methodID, jTitle, jMsg);
			t.env->DeleteLocalRef(jTitle);
			t.env->DeleteLocalRef(jMsg);
		}
	}

	void Java_com_DialogBox_org_JniTestHelper_setPackageName(JNIEnv *env, jobject thiz, jstring packageName)
	{
		const char *pkgName = env->GetStringUTFChars(packageName, NULL);
		setPackageName(pkgName);
		env->ReleaseStringUTFChars(packageName, pkgName);
	}

	void Java_com_DialogBox_org_JniTestHelper_exitApp(JNIEnv *env, jobject thiz)
	{
		exitApp();
	}

}