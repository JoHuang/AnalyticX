//
//  AnalyticXStringUtilAndroid.h
//  AnalyticX
//
//  Created by diwwu on 5/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef AnalyticX_AnalyticXStringUtilAndroid_h
#define AnalyticX_AnalyticXStringUtilAndroid_h

#include "cocos2d.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"

class AnalyticXStringUtilAndroid {

public:
    static jobjectArray jobjectArrayFromCCDictionary(cocos2d::JniMethodInfo minfo, cocos2d::__Dictionary * ccDictionary);
    static jobjectArray jobjectArrayFromStdMap(cocos2d::JniMethodInfo minfo, std::map<std::string, std::string>& stdMap);
};

#endif
