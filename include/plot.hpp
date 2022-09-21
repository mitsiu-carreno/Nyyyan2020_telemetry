#ifndef PLOT_H
#define PLOT_H

//void Plot(float, float);
//void TestPlot();

#include <vector>

struct PositionData{
  std::vector<float> x;
  std::vector<float> y;
  PositionData(){
    this->x.reserve(5000);
    this->y.reserve(5000);
  }
};

void DrawPlot(PositionData*);

class Plot{
  private:
    struct PositionData{
      // TODO: change 500
      std::vector<float> x;
      std::vector<float> y;
    } position_data;

  public:
    Plot(){
      this->position_data.x.resize(500);
      this->position_data.y.resize(500);
    }
    void UpdatePosition(float pos_x, float pos_y);

    void DrawPlot();
};

#endif
