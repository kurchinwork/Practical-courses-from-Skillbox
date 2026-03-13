//
// Created by kurchin_iu on 13.03.2026.
//

#include <string>

using namespace std;

struct logicOperation {
    bool statusScalpel = false,
         statusHemostat = false,
         statusTweezers = false,
         statusSuture = false;

    bool logicStop = statusScalpel && statusHemostat && statusTweezers && statusSuture;
};

struct instrumentsSurge {
    double coordCut_X = 0.0f,
           coordCut_Y = 0.0f;
};

struct mainStruct {
    string command = "";

    instrumentsSurge instrumentsSurge;
    logicOperation logicOperation;
};