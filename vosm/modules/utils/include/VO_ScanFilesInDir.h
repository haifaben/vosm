/************************************************************************************************
*																								*
*					IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.			*
*																								*
*	By downloading, copying, installing or using the software you agree to this license.		*
*	If you do not agree to this license, do not download, install, copy or use the software.	*
*																								*
*									License Agreement											*
*                			For Vision Open Statistical Models									*
*																								*
* Copyright (C):    2006~2011 by JIA Pei, all rights reserved.									*
*																								*
*    				VOSM is free software under the terms of the GNU Lesser General Public 		*
*					License (GNU LGPL) as published by the Free Software Foundation; 			*
*					either version 3.0 of the License, or (at your option) any later version.	*
* 					You can use it, modify it, redistribute it, etc; and redistribution and 	*
*					use in source and binary forms, with or without	modification, are permitted *
*					provided that the following conditions are met: 							*
*																								*
*					a) Redistribution's of source code must retain this whole paragraph of		*
*					copyright notice, including this list of conditions and all the following 	*
*					contents in this copyright paragraph.										*
*																								*
* 					b) Redistribution's in binary form must reproduce this whole paragraph of	*
*					copyright notice, including this list of conditions and all the following 	*
*					contents in this copyright paragraph, and/or other materials 				*
*					provided with the distribution.												*
*																								*
*					c) The name of the copyright holders may not be used to endorse or 			*
*					promote products derived from this software without specific prior 			*
*					written permission.															*
*																								*
* 					Any publications based on this code must cite the following five			*
*					papers, technic reports and on-line materials.								*
*					1) P. JIA, 2D Statistical Models, Technical Report of Vision Open 			*
*					Working Group, 2st Edition, Oct 21, 2010. 									*
*					http://www.visionopen.com/members/jiapei/publications/pei_sm2dreport2010.pdf*
* 					2) P. JIA. Audio-visual based HMI for an Intelligent Wheelchair.			*
* 					PhD thesis, University of Essex, 2010.										*
* 					http://www.visionopen.com/members/jiapei/publications/pei_phdthesis2010.pdf *
*					3) T. Cootes and C. Taylor. Statistical models of appearance for computer	*
*					vision. Technical report, Imaging Science and Biomedical Engineering,		*
*					University of Manchester, March 8 2004.										*
*					4) I. Matthews and S. Baker. Active appearance models revisited.			*
*					International Journal of Computer Vision, 60(2):135–164, November 2004.		*
*					5) M. B. Stegmann, Active Appearance Models: Theory, Extensions and Cases,	*
*					http://www2.imm.dtu.dk/~aam/main/, 2000										*
* 																								*
* Version:          0.3                                                     					*
* Author:           JIA Pei                                                 					*
* Contact:          jp4work@gmail.com                                       					*
* URL:              http://www.visionopen.com                               					*
* Create Date:      2010-11-04                                             						*
*************************************************************************************************/


#ifndef  __VO_IO__
#define  __VO_IO__

#include <vector>
#include <iostream>               // for std::cout
#include <cstring>

#include <boost/filesystem.hpp>   // includes all needed Boost.Filesystem declarations
#include "cxcore.h"
#include "cv.h"
#include "VO_Common.h"

using namespace std;
using namespace cv;
using namespace boost::filesystem;


/** 
 * @author		JIA Pei
 * @brief		IO for file scanning.
 */
class VO_IO
{
public:

    // scan all files with the "file_extension" under "dir_path" directory and sort them
    static bool                         ScanDirectory(const path &dir_path, const string& file_extension, vector<string>& files);

    // scan all annotation files
    static vector<string>               ScanNSortAnnotationInDirectory(const string& dir_path);

    // scan all image files
    static vector<string>               ScanNSortImagesInDirectory(const string& dir_path);
	
	// scale all YML files
	static vector<string>               ScanNSortXMLYMLsInDirectory(const string& dir_path);
	
	// scale all text files
	static vector<string>               ScanNSortTextFilesInDirectory(const string& dir_path);

};

#endif  // __VO_IO__

