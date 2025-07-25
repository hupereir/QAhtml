#ifndef MICROMEGAS_MICROMEGASDRAW_H__
#define MICROMEGAS_MICROMEGASDRAW_H__

#include <qahtml/QADraw.h>
#include <vector>

class TCanvas;
class TPad;
class TH1;
class TH2;

class MicromegasDraw : public QADraw
{
 public:
  MicromegasDraw(const std::string &name = "MicromegasQA");

  int Draw(const std::string &what = "ALL") override;
  int MakeHtml(const std::string &what = "ALL") override;
  int DBVarInit();

  using range_t = std::pair<double,double>;

  //! acceptable cluster size range
  void set_cluster_size_range( const range_t& value ) { m_cluster_size_range = value; }

  //! acceptable cluster multiplicity range
  void set_cluster_multiplicity_range( const range_t& value ) { m_cluster_multiplicity_range = value; }

  //! acceptable charge range
  void set_cluster_charge_range( const range_t& value ) { m_cluster_charge_range = value; }

  //! acceptable efficiency range
  void set_efficiency_range( const range_t& value ) { m_efficiency_range = value; }

 private:
  TH1* ClusterAverage(TH2*, std::string);

  // get canvas by name
  TCanvas* get_canvas(const std::string& name, bool clear = true );

  // create canbas
  TCanvas* create_canvas(const std::string &name);

  int DrawBCOInfo();
  int DrawClusterInfo();
  int DrawRawInfo();
  int DrawSummary();

  //! canvases
  std::vector<TCanvas*> m_canvas;

  //! acceptable cluster size range
  range_t m_cluster_size_range = {2,5};

  //! acceptable cluster multiplicity range
  range_t m_cluster_multiplicity_range = {2,4};

  //! acceptable cluster charge range
  range_t m_cluster_charge_range = {300,700};

  //! acceptable efficiency range
  range_t m_efficiency_range = {0.4,1.0};

};

#endif
