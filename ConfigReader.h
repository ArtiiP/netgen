/*  netgen - autorouting net generator for Polish Format map
 *  Copyright (C) 2005 Mariusz Dąbrowski 
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef ConfigReaderH
#define ConfigReaderH

#include "PFMStreamReader.h"

class ConfigReader : public PFMStreamReader {
	private:
		bool removedFound;
		int removedTmp, removedLastTmp;
	protected:
		static const int MAXTYPE = 0x20;
		bool token (const std::string& tok, const std::string& val);
	public:
		RouteParameters typeParameters [MAXTYPE];
		bool connectorType [MAXTYPE];
		int overrideNullSpeed;
		double epsilonMax;
		double epsilonMin;
		double maskSize;
		double minAngle;
		double lineSearchRadius;
		double routeSearchDistance;
		short lowestClassToCheck;
		short connectorClassesAdjustmentVariant;
		bool checkNetIntegrity;
		bool nodeOnRoadEnd;
		bool adjustConnectorClass;
		bool adjustClassesInNode;
		bool createNodeForRestriction;
		int numbersType;
		int restrictionType;
		int roadSignType;
		int roadEndType;
		int roadEndTypeLast;
		int removedType;
		int removedTypeLast;
		int noCrossingType;   
		int precision; 		
                bool isCheckOnly;
		void process ();
		ConfigReader (std::istream& istr);
		bool isRoadEnd (int type);
		bool isRemoved (int type);
		bool isConnector (int type);
		bool isRestrictionOrRoadSign (int type);
		bool isRoadSign (int type);
		void dumpParameters ();
   
};

#endif
