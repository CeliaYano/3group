#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert> // assert()
class ComputerAssemble{
public:
  enum CAssemble{MONITOR, KEYBOARD, MOUSE, PRINTER, NPARTS};
  ComputerAssemble(CAssemble id) : id(id){}
  friend std::ostream&
  operator<<(std::ostream&, const PotPart&);
private:
  static std::string parts[NPARTS];
  CAssemble id;
};
std::string ComputerAssemble::parts[NPARTS] = {"Monitor","Keyboard", "Mouse", "Printer"};
std::ostream&
operator<<(std::ostream& out, const ComputerAssemble& computer){
  return out << computer.parts[computer.id];
}
class Computer{
  std::vector<ComputerAssemble*> parts;
public:
  ~Computer();
  void addPart(ComputerAssemble* part){ parts.push_back(part); }
  friend std::ostream&
  operator<<(std::ostream&, const Computer&);
};
std::ostream&
operator<<(std::ostream& out, const Computer& computer){
  out << " has [";
  for(auto part: computer.parts) out << (*part) << ' ';
  return out << ']';
}
class ComputerBuilder{ //!NOTE: the `builder' class.
protected:
  Computer* computer;
public:
  ComputerBuilder(): computer(0){}
  void createComputer(){ computer = new Computer; }
  virtual void buildMonitor() = 0;
  virtual void buildKeyboard() = 0;
    virtual void buildMouse() = 0;
    virtual void buildPrinter() = 0;
  virtual std::string getComputerName() const = 0;
  Computer* getComputerName(){
    Computer* newcomputer = computer;
    computer = 0;
    return newcomputer;
  }
};
class LenovoBuilder : public ComputerBuilder{
public:
  void buildMonitor(){
    computer->addPart(new ComputerAssemble(ComputerAssemble::Monitor));
  }
  void buildKeyboard(){
      computer->addPart(new ComputerAssemble(ComputerAssemble::Keyboard));
} 
  void buildMouse(){
      computer->addPart(new ComputerAssemble(ComputerAssemble::Mouse));
}
  void buildPrinter(){}
  std::string getComputerName() const{
    return "This is Lenovo!!";
  }
};
class HpBuilder : public ComputerBuilder{
   void buildMonitor(){
    computer->addPart(new ComputerAssemble(ComputerAssemble::Monitor));
  }
  void buildKeyboard(){
      computer->addPart(new ComputerAssemble(ComputerAssemble::Keyboard));
} 
  void buildMouse(){
      computer->addPart(new ComputerAssemble(ComputerAssemble::Mouse));
}
  void buildPrinter(){ computer->addPart(new ComputerAssemble(ComputerAssemble::Printer))}
  std::string getComputerName() const{
    return "This is HP Printer!!";
  }
};
class MacBuilder : public ComputerBuilder{
   void buildMonitor(){
    computer->addPart(new ComputerAssemble(ComputerAssemble::Monitor));
  }
  void buildKeyboard(){
      computer->addPart(new ComputerAssemble(ComputerAssemble::Keyboard));
} 
  void buildMouse(){
      computer->addPart(new ComputerAssemble(ComputerAssemble::Mouse));
}
  void buildPrinter(){ computer->addPart(new ComputerAssemble(ComputerAssemble::Printer))}
  std::string getComputerName() const{
    return "This is Mac!!";
  }
};
class IpodBuilder : public ComputerBuilder{
   void buildMonitor(){
    computer->addPart(new ComputerAssemble(ComputerAssemble::Monitor));
  }
  void buildKeyboard(){} 
  void buildMouse(){
      computer->addPart(new ComputerAssemble(ComputerAssemble::Mouse));
}
  void buildPrinter(){}
  std::string getComputerName() const{
    return "This is Ipod!!";
  }
};
class Nee{
  ComputerBuilder* builder;
public:
  Architect() : builder(0){}
  void setBuilder(ComputerBuilder* builder){
    this->builder = builder;
  }
  void make(){
    assert(builder);
    builder->createComputer();
    builder->buildMonitor();
    builder->buildKeyboard();
    builder->buildMouse();
    builder->buildPrinter();
}
};
using namespace std;
Computer *
makeAComputer(Architect& architect, ComputerBuilder* pattern){
  architect.setBuilder(pattern);
  architect.make();
  Computer* computer = pattern->getComputer();
  cout << "Made a " << pattern->getComputerName() << endl;
  return computer;
}
int main(){
  map<string, int> laboratory;
  laboratory["lenovo"] = 4;
  laboratory["Hp Printer"]     = 2;
  laboratory["Mac"] =5;
  laboratory["Ipod"] =24;

  vector<Computer*> containers;
  HpBuilder* cpb = new HpBuilder;
  LenovoBuilder* tmb = new LenovoBuilder;
  IpodBuilder* imp= new IpodBuilder;
  MacBuilder* mmb = new MacBuilder;
  Architect architect;
  map<string, int>::const_iterator cit = laboratory.begin();
  while(cit != laboratory.end()){
    ComputerBuilder* pattern;
    if(cit->first == "Lenovo")
      pattern = tmb;
    else if(cit->first == "Hp Printer")
      pattern = cpb;
    else if(cit->first == "Mac")
      pattern = cpb;
    else if(cit->first == "Ipod")
      pattern = cpb;
    for(int i = 0; i < cit->second; ++i)
      containers.push_back(makeComputer(architect, pattern));
    ++cit;
  }
  delete tmb;
  delete cpb;
  delete imp;
  delete mmb;
  int i = 0;
  for(auto container: containers)
    cout << "Container " << i++
         << " " << (*container) << endl;
}
