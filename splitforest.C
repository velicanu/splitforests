#include "HiForestAnalysis/hiForest.h"
#include <iostream>

void splitforest(string forest, int start, int end)
{
  HiForest * c = new HiForest(forest.data(),"forest",cPbPb,0);
  c->SetOutputFile(Form("/tmp/splitforest_%d_to_%d.root",start,end));
  int nentries = c->GetEntries();
  if( end > nentries ) end = nentries;
  for(int i = start ; i < end ; ++i)
  {
    if(i%1000==0) cout<<i<<"/"<<end<<endl;
    c->GetEntry(i);
    c->FillOutput(); 
  }
  delete c;
}

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    std::cout << "Usage: <input> <start> <end>" << std::endl;
    return 1;
  }
  splitforest(argv[1],std::atoi(argv[2]),std::atoi(argv[3]));
  return 0;
}

