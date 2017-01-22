#The places to look for the tinyxml2 folders
set(FIND_LIBDS_PATHS                       #On Windows, this is where my tinyxml2 folder is
        ~/Desktop/BitDefenderC/Nagy_Lilla_Proiect/libraries      #On Mac, this is where my tinyxml2 folder is
        )

#The location of the include folder (and thus the header files)
#find_path uses the paths we defined above as places to look
#Saves the location of the header files in a variable called TINYXML2_INCLUDE_DIR
find_path(LIBDS_INCLUDE_DIR HashTable.h LinkedList.h   #The variable to store the path in and the name of the header files
        PATH_SUFFIXES include               #The folder name containing the header files
        PATHS ${FIND_LIBDS_PATHS})       #Where to look (defined above)

#The location of the lib folder (and thus the .a file)
#find_library uses the paths we defined above as places to look
#Saves the location of the .a file in a variable called TINYXML2_LIBRARY
find_library(LIBDS_LIBRARY               #The variable to store where it found the .a files
        NAMES libds                      #The name of the .a file (without the extension and without the 'lib')
        PATH_SUFFIXES lib                   #The folder the .a file is in
        PATHS ${FIND_LIBDS_PATHS})       #Where to look (defined above)