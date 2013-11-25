var fs = require('fs'),
    path = require('path');

module.exports = function(grunt) {
  grunt.loadNpmTasks('grunt-contrib-jshint');
  grunt.initConfig({
    jshint: {
      all: ['Gruntfile.js', '**/*.js']
    }
  });

/*
  grunt.registerTask('moveApps', 'Move apps inside gaia-essential to build.', function() {
    var done = this.async();
    var cwd = path.resolve(__dirname);
    var apps = cwd + '/apps';
    // We assume the whole Gaia apps would be put inside BUILD/apps,
    // so we just need to move them to the upper directory.
    fs.readdir(apps, function(err, files){
      if (err)
        throw err;
      files.forEach(function(fn, i, a){
        fs.rename(apps+'/'+fn, cwd+'/../'+fn, function(err){
          if (err)
            throw err;
          done();
        });
      });
    });
  });

  grunt.registerTask('build', ['moveApps']);
*/
  grunt.registerTask('build', function(){
    // Do nothing.
  });
  grunt.registerTask('default', ['jshint']);
}
