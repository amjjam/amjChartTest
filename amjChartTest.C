#include "amjChartTest.H"
#include "ui_amjChartTest.h"

#include <cmath>

amjChartTest::amjChartTest(QWidget *parent)
  : QMainWindow(parent), ui(new Ui::amjChartTest){
  ui->setupUi(this);
  connect(&timer,&QTimer::timeout,this,&amjChartTest::append);
  timer.start(100);
}

amjChartTest::~amjChartTest(){
  delete ui;
}

void amjChartTest::update_npanels(int n){
  ui->chart->npanels(n);
}

void amjChartTest::update_ngraphs(int n){
  ui->chart->ngraphs(n);
}

void amjChartTest::update_npanelnames(int n){
  std::vector<std::string> panelnames(n);
  for(int i=0;i<n;i++)
    panelnames[i]="panel "+std::to_string(i+1);
  ui->chart->panelnames(panelnames);
}

void amjChartTest::update_ngraphnames(int n){
  std::vector<std::string> graphnames(n);
  for(int i=0;i<n;i++)
    graphnames[i]="graph "+std::to_string(i+1);
  ui->chart->graphnames(graphnames);
}

void amjChartTest::update_showLegend(int state){
  if(state==Qt::Checked)
    ui->chart->legendShow(true);
  else
    ui->chart->legendShow(false);
}

void amjChartTest::update_nInLegend(int n){
  std::vector<int> legend_graphs(n);
  for(unsigned int i=0;i<legend_graphs.size();i++)
    legend_graphs[i]=i;
  ui->chart->legendList(legend_graphs);
}

void amjChartTest::update_nLegendWrap(int n){
  ui->chart->legendWrap(n);
}

void amjChartTest::update_showToolbar(int state){
  if(state==Qt::Checked)
    ui->chart->toolbarShow(true);
  else
    ui->chart->toolbarShow(false);
}

void amjChartTest::append(){
  if(ui->chart->ngraphs()==0)
    return;
  QVector<double> v(ui->chart->ngraphs());
  QDateTime t=QDateTime::currentDateTimeUtc();
  for(int i=0;i<ui->chart->ngraphs();i++)
    v[i]=cos(((double)t.toMSecsSinceEpoch()/1000.0)*2*M_PI/(5.0+(double)i/2));
  ui->chart->append(t,v);
}
