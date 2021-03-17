# Resource_management

-------------------------------------------------------------------------
Repo for Finoa Task
Use following command to clone.
<pre>git clone https://github.com/medhiraj/resource_management.git --recursive</pre>
The naviagte to resource_management/resource_management/
cmd:
<pre>cd resource_management/resource_management/<pre>

===========================================================================
create directory, for eg : build 
Nvaigate to build directory .
cmd
<pre>cd build</pre>
(This step can be skipped as its purpose is to have a sepaerate build folder)
=============================================================================

Now build the project,
cmd:
<pre>cmake .. -DCMAKE_BUILD_TYPE=Debug -G &quot;Unix Makefiles&quot;</pre>

Now run make cmd.
cmd:
<pre>make all</pre>

Now you can run a google test suit if project builds suucesfully

<pre>./gtest/ResourceManagement_tst </pre>
Everything should be pass and green.
