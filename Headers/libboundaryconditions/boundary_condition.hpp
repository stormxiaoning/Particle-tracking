/**
 * @file boundary_condition.hpp
 * @author Olivier Delestre <olivierdelestre41@yahoo.fr> (2008)
 * @author Christian Laguerre <christian.laguerre@math.cnrs.fr> (2012-2015)
 * @version 1.06.00
 * @date 2017-03-20
 *
 * @brief Boundary condition
 * @details 
 * Common part for all the boundary conditions.
 *
 * @copyright License Cecill-V2 \n
 * <http://www.cecill.info/licences/Licence_CeCILL_V2-en.html>
 *
 * (c) CNRS - Universite d'Orleans - BRGM (France)
 */
/* 
 *
 * This file is part of FullSWOF_2D software. 
 * <https://sourcesup.renater.fr/projects/fullswof-2d/> 
 *
 * FullSWOF_2D = Full Shallow-Water equations for Overland Flow, 
 * in two dimensions of space.
 * This software is a computer program whose purpose is to compute
 * solutions for 2D Shallow-Water equations.
 *
 * LICENSE
 *
 * This software is governed by the CeCILL license under French law and
 * abiding by the rules of distribution of free software. You can use,
 * modify and/ or redistribute the software under the terms of the CeCILL
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * <http://www.cecill.info>.
 *
 * As a counterpart to the access to the source code and rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty and the software's author, the holder of the
 * economic rights, and the successive licensors have only limited
 * liability.
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading, using, modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean that it is complicated to manipulate, and that also
 * therefore means that it is reserved for developers and experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or
 * data to be ensured and, more generally, to use and operate it in the
 * same conditions as regards security.
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL license and that you accept its terms.
 *
 ******************************************************************************/

#ifndef PARAMETERS_HPP
#include "parameters.hpp"
#endif

#ifndef BOUNDARY_CONDITION_HPP
#define BOUNDARY_CONDITION_HPP

/** @class Boundary_condition
 * @brief Boundary condition
 * @details 
 * Class that contains all the common declarations for the boundary conditions.
 * @todo Add time and space dependancy in the boundary conditions.
 * @todo Improve boundary conditions at the second order for the wall and periodic conditions.
 * @todo Take into account source terms (friction and topography) in the boundary conditions, see \cite LeRoux01, \cite Bristeau01.
 */


class Boundary_condition{
  
  public :
  
    /** @brief Constructor */
    Boundary_condition(Parameters &);
  
    /** @brief Function to be specified in each boundary condition */
    virtual void calcul(SCALAR, SCALAR, SCALAR, SCALAR, SCALAR, SCALAR, SCALAR, SCALAR, SCALAR, int, int) =0;
  
    /** @brief Gives the water height on the fictive cell */
    SCALAR get_hbound() const;
  
    /** @brief Gives the normal velocity of the flow on the fictive cell */
    SCALAR get_unormbound() const;
  
    /** @brief Gives the tangential velocity of the flow on the fictive cell */
    SCALAR get_utanbound() const;
  
    /** @brief Destructor */
    virtual ~Boundary_condition();
    
  protected :
    /** Number of cells (in space) in the x direction. */
    const int NXCELL;
    /** Number of cells (in space) in the y direction. */
    const int NYCELL;
    /** Water height on the fictive cell, to be specified in each boundary condition. */
    SCALAR hbound;
    /** Normal velocity on the fictive cell, to be specified in each boundary condition. */
    SCALAR unormbound;
    /** Tangential velocity on the fictive cell, to be specified in each boundary condition. */
    SCALAR utanbound;
    /** Imposed value of the velocity from Parameters#left_imp_discharge (or Parameters#right_imp_discharge, Parameters#bottom_imp_discharge, Parameters#top_imp_discharge) and Parameters#left_imp_h (or Parameters#right_imp_h, Parameters#bottom_imp_h, Parameters#top_imp_h). */
    SCALAR unormfix;
  
  map<int,int> Choice_Lbound;
  map<int,int> Choice_Rbound;
  map<int,int> Choice_Bbound;
  map<int,int> Choice_Tbound;
    
};
#endif
