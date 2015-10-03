//
//  AnalyticX.cpp
//  AnalyticX
//
//  Created by diwwu on 5/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "AnalyticX.h"

#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#include "AnalyticXStringUtilAndroid.h"
#include <string>

using namespace std;

void AnalyticX::flurryLogEvent(const char * eventName, ...) {
    
    // take the size directly from cocos2d's cocos2d::kMaxLogLen
    char szBuf[16*1024];
    
    va_list ap;
    va_start(ap, eventName);
    vsprintf(szBuf, eventName, ap);
    va_end(ap);
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurryLogEvent");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,szBuf);
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");

        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurryLogEventTimed(const char * eventName, bool timed) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurryLogEventTimed");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,eventName);
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        if (timed == true) {
            stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"true");

        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurryLogEventWithParameters(const char * eventName, std::map<std::string, std::string>& parameters) {
    cocos2d::JniMethodInfo minfo;

    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;)V"); 

    if (!isHave) {
        //do nothing
    } else {
        string eventNameString("flurryLogEventWithParameters,");
        eventNameString += eventName;
		jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,eventNameString.c_str());
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");

        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, AnalyticXStringUtilAndroid::jobjectArrayFromStdMap(minfo, parameters), stringArg2);

    }
}

void AnalyticX::flurryLogEventWithParametersTimed(const char * eventName, std::map<std::string, std::string>& parameters, bool timed) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        string eventNameString("flurryLogEventWithParametersTimed,");
        eventNameString += eventName;
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,eventNameString.c_str());
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        if (timed == true) {
            stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"true");
        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, AnalyticXStringUtilAndroid::jobjectArrayFromStdMap(minfo, parameters), stringArg2);
        
    }
}

// Since Flurry for Android does not support *parameters* in *endTimedEvent()*.
// This *parameters* will be ignored when running in Android
void AnalyticX::flurryEndTimedEventWithParameters(const char * eventName, std::map<std::string, std::string>& parameters) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurryEndTimedEvent");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,eventName);
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurryLogPageView() {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurryLogPageView");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"placeholder");
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurrySetAppVersion(const char * version) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurrySetAppVersion");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,version);
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

const char * AnalyticX::flurryGetFlurryAgentVersion() {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","flurryGetAgentVersion", "()I"); 
    
    if (!isHave) {
        //do nothing
        return NULL;
    } else {
        jint version =  minfo.env->CallStaticIntMethod(minfo.classID, minfo.methodID);
        static char result[20];
        sprintf(result, "%d", version);
        return result;
    }
}

void AnalyticX::flurrySetShowErrorInLogEnabled(bool value) {
    //do nothing on Android
    //only supported in iOS
}

void AnalyticX::flurrySetDebugLogEnabled(bool value) {
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurrySetLogEnabled");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"placeholder");
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        if (value == true) {
            stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"true");
        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurrySetSessionContinueSeconds(int seconds) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","flurrySetSessionContinueSecond", "(I)V"); 
    
    if (!isHave) {
        //do nothing
    } else {        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, (jint)seconds);
    }
}

void AnalyticX::flurrySetSecureTransportEnabled(bool value) {
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurrySetSecureEnabled");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"placeholder");
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        if (value == true) {
            stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"true");
        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurryStartSession(const char * apiKey) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurryOnStartSession");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,apiKey);
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurryEndSession() {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurryOnEndSession");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"placeholder");
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurrySetUserID(const char * userID) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurrySetUserID");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,userID);
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurrySetAge(int age) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","flurrySetAge", "(I)V"); 
    
    if (!isHave) {
        //do nothing
    } else {        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, (jint)age);
    }
}


void AnalyticX::flurrySetGender(const char * gender) {
    
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurrySetGender");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"female");
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        if (strcmp(gender, "m") == 0) {
            stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"male");
        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
    
}

void AnalyticX::flurrySetLatitudeLongitudeHorizontalAccuracyVerticalAccuracy(double latitude, double longitude, float horizontalAccuracy, float verticalAccuracy) {
    // Not supported in Android
}

void AnalyticX::flurrySetReportLocation(bool reportLocation) {
    cocos2d::JniMethodInfo minfo;
    
    bool isHave = cocos2d::JniHelper::getStaticMethodInfo(minfo,"com/diwublog/AnalyticX/AnalyticXBridge","Bridge", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"); 
    
    if (!isHave) {
        //do nothing
    } else {
        jstring stringArg0 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"flurryReportLocation");
        jstring stringArg1 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"placeholder");
        jstring stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"false");
        
        if (reportLocation == true) {
            stringArg2 = cocos2d::StringUtils::newStringUTFJNI(minfo.env,"true");
        }
        
        minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, stringArg0, stringArg1, stringArg2);
    }
}

void AnalyticX::flurrySetSessionReportsOnCloseEnabled(bool sendSessionReportsOnClose) {
    //iOS only
}

void AnalyticX::flurrySetSessionReportsOnPauseEnabled(bool setSessionReportsOnPauseEnabled) {
    //iOS only
}

void AnalyticX::flurrySetEventLoggingEnabled(bool value) {
    //iOS only
}









