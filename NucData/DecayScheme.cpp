#include "DecayScheme.h"
#include <cmath>
#include <boost/math/special_functions/fpclassify.hpp>
#include <algorithm>
#include "custom_logger.h"

DecayScheme::DecayScheme(const std::string &name,
               const Nuclide &parentNuclide,
               const Nuclide &daughterNuclide,
               Type DecaySchemeType)
  : decay_type_(DecaySchemeType)
  , name_(name)
  , parent_(parentNuclide)
  , daughter_(daughterNuclide)
{
}

bool DecayScheme::valid() const
{
  return (!parent_.empty() && !daughter_.empty());
}

std::string DecayScheme::DecayTypeAsText(Type type)
{
  switch (type) {
  case ElectronCapture:
    return "Electron Capture";
  case BetaPlus:
    return "β+";
  case BetaMinus:
    return "β-";
  case IsomericTransition:
    return "Isomeric Transition";
  case Alpha:
    return "α";
  default:
    return "";
  }
}

std::string DecayScheme::name() const
{
  return name_;
}

DecayScheme::Type DecayScheme::type() const
{
  return decay_type_;
}

Nuclide DecayScheme::parentNuclide() const
{
  return parent_;
}

Nuclide DecayScheme::daughterNuclide() const
{
  return daughter_;
}