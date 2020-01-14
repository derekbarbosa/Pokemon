#ifndef GameCommand_H_
#define GameCommand_H_

#include "Model.h"
#include "Input_Handling.h"

//CHECK README FOR CHANGES
void DoMoveCommand(Model& model);

void DoMoveToCenterCommand(Model& model);

void DoMoveToGymCommand(Model& model);

void DoMoveToArenaCommand(Model& model);

void DoStopCommand(Model& model);

void DoTrainInGymCommand(Model& model);

void DoRecoverInCenterCommand(Model& model);

void DoBattleInArenaCommand(Model& model);

void DoGoCommand(Model& model, View& View);

void DoRunCommand(Model& model, View& View);

void DoNewCommand(Model& model);

#endif 