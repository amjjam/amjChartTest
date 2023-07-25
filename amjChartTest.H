#ifndef AMJCHARTTEST_H
#define AMJCHARTTEST_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class amjChartTest; }
QT_END_NAMESPACE

class amjChartTest : public QMainWindow
{
  Q_OBJECT

public:
  amjChartTest(QWidget *parent = nullptr);
  ~amjChartTest();
public slots:
  void update_npanels(int);
  void update_ngraphs(int);
  void update_npanelnames(int);
  void update_ngraphnames(int);
  void update_showLegend(int);
  void update_nInLegend(int);
  void update_nLegendWrap(int);
  void update_showToolbar(int);
private:
  Ui::amjChartTest *ui;
  QTimer timer;
  void append();
};
#endif // AMJCHARTTEST_H
