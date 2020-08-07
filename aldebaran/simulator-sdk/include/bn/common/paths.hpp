/* -*- Mode: C++;  -*- */
/**
 * @author Cedric GESTES <gestes@aldebaran-robotics.com>
 * Aldebaran Robotics (c) 2008 All Rights Reserved - This file is confidential.
 *
 * Version : $Id$
 */

#ifndef   	PATHS_H_
# define   	PATHS_H_

# include <string>
# include <vector>
# include <bn/common.hpp>

/**
 * TODO: need to be completed
 */

namespace bn
{
  /**
   * @brief this class find the path of a file
   * (handle ro and rw folder)
   */
  class Paths {
  public:
    ///ctor
    Paths();

    /**
     * set the name of the project
     */
    void setName(const std::string &name);

    /**
     * add a new readonly search path
     * if appendName is true, the function concat the name with the project
     * name set with setName
     */
    void addRoPath(const std::string &name, sInt32 appendName = 1);

    /**
     *  find a file
     *  this function search for file that dont need write access
     *  should be used for static data
     */
    std::string findRoFile(const std::string &fname) const;

    /**
     * find a file
     * search for writable file
     * if the file is found in a ro folder, the file is copied into a writable folder
     * should be used for configuration files and files that change
     */
    const std::string &findRwFile(const std::string &fname) const;

  protected:
    std::vector<std::string>    fRoPaths;
    std::string                 fRwPath;
    std::string                 fProjectName;
  };

} //namespace bn

#endif 	    /* !PATHS_H_ */
