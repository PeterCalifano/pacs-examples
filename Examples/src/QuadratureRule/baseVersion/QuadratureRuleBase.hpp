#ifndef HH_QUADRATURERULEBASE_HH
#define HH_QUADRATURERULEBASE_HH
#include <memory>
#include <functional>

namespace NumericalIntegration{
  
  //! The type the integrand
  using FunPoint=std::function<double (double const &)>;
  
  //! forward declaration
  class QuadratureRule;
  //! The type of the object holding the quadrature rule.
  using QuadratureRuleHandler=std::unique_ptr<QuadratureRule>;

  //! The basis class for all the basic integration rules
  /*
    This basis class is the common class for all numerical integration 
    formulae that approximate the integral \f$ \int_{-1}^{1} f(y) dy\f$.
    It's a very light class (no variable members) that provides
    the common interface to all integration rules.

    Constructors and assignement operators
    are not defined since the synthetic ones are sufficient.
  */
  class QuadratureRule
  {
  public:
    //! The class is clonable.
    /*!
      Having a clonable class makes it possible to write copy constructors
      and assignment operators for classes that aggregate object of the
      QuadratureRule hierarchy by composition.
    */
    virtual QuadratureRuleHandler clone() const =0;
    // Applies the rule in the interval (a,b)
    
    virtual double apply(FunPoint const & f, double const &a, 
			 double const & b)const=0;
    virtual ~QuadratureRule()=default;
    /*! To be able to use the rule in the context of adaptive quadrature
      when I will load rules dynamically I need to enrich the interface 
      with these functions that in case of normal rules do just nothing.
    */
    virtual void setTargetError(double const a){}
    virtual void setMaxIter(unsigned int n){}
  };
}
#endif
