/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2009 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef __gdcmDICOMDIRGenerator_h
#define __gdcmDICOMDIRGenerator_h

#include "gdcmDirectory.h"

namespace gdcm
{
class File;
class Scanner;
class SequenceOfItems;
class VL;
class DICOMDIRGeneratorInternal;
/**
 * \brief DICOMDIRGenerator 
 */
class GDCM_EXPORT DICOMDIRGenerator
{
  typedef Directory::FilenamesType  FilenamesType;
public:
  DICOMDIRGenerator();
  ~DICOMDIRGenerator();

  void SetFilesames( FilenamesType const & fns );

  bool Generate();

  void SetFile(const File& f);
  File &GetFile();

protected:
  Scanner &GetScanner();
  bool AddPatientDirectoryRecord();
  bool AddStudyDirectoryRecord();
  bool AddSeriesDirectoryRecord();
  bool AddImageDirectoryRecord();

private:
  bool TraverseDirectoryRecords(const SequenceOfItems *sqi, VL start );

  DICOMDIRGeneratorInternal * Internals;
};

} // end namespace gdcm

#endif //__gdcmDICOMDIRGenerator_h
