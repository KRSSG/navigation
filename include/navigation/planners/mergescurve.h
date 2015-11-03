#ifndef MERGE_S_CURVE_H
#define MERGE_S_CURVE_H
#include <vector>
#include <list>
#include "ssl_common/geometry.hpp"
#include "common.h"

namespace Navigation {
class MergeSCurve
  {
  private:
    static const float x_min;
    static const float x_max;
    static const float y_min;
    static const float y_max;

    obstacle* Obstacles;
    int nObstacles;
    int nBotID;

  public:
    MergeSCurve();
    ~MergeSCurve();

    bool plan(const Vector2D<int>& initial,
              const Vector2D<int>& final,
              Vector2D<int> *pt1,
              Vector2D<int> *pt2,
              obstacle *obstacles,
              int obstacle_count,
              int current_id,
              bool teamBlue);

  private:
    int             MergeObstacles();
    void            ConnectObstacles(bool *Connected, int nCurrentObstacle);
    int             ifInObstacle(Vector2D<int> point, obstacle *obs, int nObs, int closest);
    int             Connect(Vector2D<int> Start, Vector2D<int> End, obstacle* obs, int nObs, int BotID, int *nearest, bool TeamBlue);
    Vector2D<int> getNextPt(Vector2D<int> initial, int closest, Vector2D<int> final, obstacle *obstacles, int nObs, int BotID, bool teamBlue);
    Vector2D<int> getNextPtRec(Vector2D<int> initial, int lastClosest, int closest, obstacle *obstacles, int nObs);
  }; // class MergeSCurve
  
}
#endif