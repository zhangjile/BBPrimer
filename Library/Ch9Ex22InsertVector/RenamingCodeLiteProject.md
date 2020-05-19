## how to rename a CodeLite project?

1. remove the project from it's current workspace

2. rename project folder from Chapter9Ex22InsersionInVector, which is too long to be displayed, to Ch9Ex22InsertVector

3. edit Libraries.workspace, replace.

4. edit Chapter9Ex22InsersionInVector.project, replace.

5. add an existing project and select Ch9Ex22InsertVector.project

this workaround ensures that Ch9Ex22InsertVector project is git versioned properly.

## abandon a less perfect workspace name

1. create a new workspace named Library in BBPrimer
2. move all the projects to Library directory
3. select 'add an existing project' and reunite the projects in Library workspace
4. clean up Libraries workspace directory