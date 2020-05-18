## how to rename a CodeLite project?
1. remove the project from it's current workspace
2. rename project folder from Chapter9Ex22InsersionInVector to Ch9Ex22InsertVector
3.edit Libraries.workspace, replace.
4. edit old.project, replace
5. add an existing project and select Ch9Ex22InsertVector.project

this workaround ensures that Ch9Ex22InsertVector project is git versioned properly.