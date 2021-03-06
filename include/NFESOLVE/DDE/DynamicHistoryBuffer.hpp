#ifndef DYNAMICHISTORYBUFFERHEADERDEF
#define DYNAMICHISTORYBUFFERHEADERDEF

#include <armadillo>

class DynamicHistoryBuffer
{
public:
  // Constructor
  DynamicHistoryBuffer(const int sysSize, const int bufferLength, const double maxDelay);

  void AddEntry(const arma::vec& solution, const arma::vec& derivative, const double time);

  arma::vec ComputeDelayState(double time) const;
  double ComputeDelayState(double time, arma::uword solIndex) const;
  arma::vec ComputeDelayState(double time, arma::uvec solIndices) const;

  void SetMaxDelay(const double maxDelay);

  const arma::mat& GetSolutionBuffer() const;
  const arma::mat& GetDerivativeBuffer() const;
  const arma::rowvec& GetTimeBuffer() const;
  int GetColStart() const;
  int GetBufferLength() const;
  bool IsBufferFull() const;

private:
  int mBufferLength;
  int mSysSize;
  double mMaxDelay;

  arma::mat mSolutionBuffer;
  arma::mat mDerivativeBuffer;
  arma::rowvec mTimeBuffer;

  void ExpandBuffer(const int numCols);

  int mColStart = 0;
  int mNumEntries = 0;
  bool mBufferFull = false;
};

#endif
